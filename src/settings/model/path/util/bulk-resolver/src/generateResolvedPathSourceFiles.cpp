
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

#include "settings/model/path/generateResolvedPathSourceFiles.h"

struct ResolvedPath {
  std::string dottedPath;
  std::vector<uint32_t> tags;
  bool isIndirect;
  AutoCompleteTrigger trigger;
};

static void generatePaths(
    const FieldEntry* table,
    const std::string& prefix,
    const std::vector<uint32_t>& currentTags,
    std::vector<ResolvedPath>& paths)
{
  if (table == nullptr) return;

  const FieldEntry* entry = table;
  while (entry->name != nullptr) {
    std::string currentPath = prefix.empty()
        ? std::string(entry->name)
        : prefix + "." + entry->name;

    // Add current tag to path
    std::vector<uint32_t> tags = currentTags;
    tags.push_back(entry->tag);

    // Store this resolved path with all metadata
    paths.push_back({currentPath, tags, entry->isIndirect, entry->trigger});

    // Recurse into submessages
    if (entry->submsg != nullptr) {
      generatePaths(entry->submsg, currentPath, tags, paths);
    }

    entry++;
  }
}

void generateResolvedPathSourceFiles(const FieldEntry* fieldEntries, const char* baseName)
{
  std::vector<ResolvedPath> allPaths;

    // Generate all dotted paths with their resolved tags
    std::vector<uint32_t> emptyTags;
    generatePaths(fieldEntries, "", emptyTags, allPaths);

    // Output files
    std::ostringstream oss;
    oss << baseName << ".h";
    std::string headerFile = oss.str();
    // std::string headerFile = std::format("{}.h", baseName);
    oss.str("");  // Clear the string content
    oss.clear();  // Clear the error flags
    oss << baseName << ".cpp";
    std::string sourceFile = oss.str();
    // std::string sourceFile = std::format("{}.cpp", baseName);


    // Generate header file
    std::ofstream hFile(headerFile);
    hFile << "#pragma once\n";
    hFile << "#include <settings/model/base/SettingDescriptor.h>\n\n";
    hFile << "// Auto-generated pre-resolved field descriptors\n";
    hFile << "// Uncomment the ones you need, likewise in " << sourceFile << "\n";
    // hFile << "namespace FieldPaths {\n\n";

    for (const auto& path : allPaths) {
        // Convert dotted path to valid C++ identifier
        std::string identifier = path.dottedPath;
        for (char& c : identifier) {
            if (c == '.') c = '_';
        }

        hFile << "// extern const SettingDescriptor " << identifier << ";\n";
    }

    // hFile << "\n} // namespace FieldPaths\n";
    hFile.close();

    // Generate source file
    std::ofstream cppFile(sourceFile);
    cppFile << "#include \"" << headerFile << "\"\n\n";
    cppFile << "// Pre-resolved field descriptors (no string processing at runtime)\n";
    cppFile << "// Uncomment the ones you need, likewise in " << headerFile << "\n";
    // cppFile << "namespace FieldPaths {\n\n";

    for (const auto& path : allPaths) {
        // Convert dotted path to valid C++ identifier
        std::string identifier = path.dottedPath;
        for (char& c : identifier) {
            if (c == '.') c = '_';
        }

        // Generate the SettingDescriptor with SettingPath, trigger, and isIndirect
        cppFile << "/*\n";
        cppFile << "const SettingDescriptor " << identifier << " = SettingDescriptor(\n";
        cppFile << "    SettingPath{";
        for (size_t i = 0; i < path.tags.size(); ++i) {
            if (i > 0) cppFile << ", ";
            cppFile << path.tags[i];
        }
        cppFile << "},\n";
        cppFile << "    AutoCompleteTrigger::" << (path.trigger == AutoCompleteTrigger::NONE ? "NONE" :
                                                    path.trigger == AutoCompleteTrigger::MODE ? "MODE" :
                                                    path.trigger == AutoCompleteTrigger::BAND ? "BAND" : "NONE") << ",\n";
        cppFile << "    " << (path.isIndirect ? "true" : "false") << "\n";
        cppFile << ");\n";
        cppFile << "*/\n";
    }

    // cppFile << "\n} // namespace FieldPaths\n";
    cppFile.close();

    std::cout << "Generated " << allPaths.size() << " pre-resolved field descriptors:\n";
    std::cout << "  " << headerFile << "\n";
    std::cout << "  " << sourceFile << "\n";
}