#include "settings/model/lookup/resolveDottedPath.h"
#include "settings/model/lookup/MessageTagLookup.h"
#include <CrossPlatformTypes.h>

ResultCode resolveDottedPath(
  const char* dottedPath,
  SettingPath& path,
  bool* isIndirectOut,
  AutoCompleteTrigger* triggerOut
)
{
  const FieldEntry* current_table = radio_fields;
  int tag_count = 0;

  const char* p = dottedPath;
  char field_name[MAX_FIELD_NAME_LENGTH];
  bool isIndirect = false;
  AutoCompleteTrigger trigger = AutoCompleteTrigger::NONE;

  while (*p && tag_count < MAX_FIELD_PATH_LENGTH) {
    // Extract next field name
    int i = 0;
    while (*p && *p != '.' && i < 63) {
      field_name[i++] = *p++;
    }
    field_name[i] = '\0';
    if (*p == '.') p++;  // Skip dot

    // Search in current table
    const FieldEntry* entry = current_table;
    bool found = false;
    while (entry != nullptr && entry->name != nullptr) {
      if (strcmp(entry->name, field_name) == 0) {
        path.push_back(entry->tag);
        tag_count++;
        current_table = entry->submsg;
        if (entry->isIndirect) {
          isIndirect = true;
        }
        if (current_table == nullptr) {
          // We're at the leaf. Save the AutoComplete trigger
          trigger = entry->trigger;
        }
        found = true;
        break;
      }
      entry++;
    }

    if (!found) {
      return ResultCode::ERR_SETTING_PATH_NOT_FOUND;
    }
    if (current_table == nullptr) {
      if (*p != '\0') {
        return ResultCode::ERR_SETTING_DOTTED_STRING_NOT_VALID;
      }
    }
  }
  *isIndirectOut = isIndirect;
  *triggerOut = trigger;
  return tag_count > 0 ? ResultCode::OK : ResultCode::ERR_SETTING_PATH_NOT_FOUND;
}
