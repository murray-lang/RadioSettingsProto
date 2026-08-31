#pragma once

#include <settings/model/AutoCompleteTrigger.h>
#include <cstdint>

#define MAX_FIELD_NAME_LENGTH 32

// Field name to tag mappings (organized by message type)
struct FieldEntry {
  const char* name{};
  int32_t tag{};
  const FieldEntry* submsg{};  // Pointer to submessage field table, or nullptr
  bool isIndirect = false;
  AutoCompleteTrigger trigger = AutoCompleteTrigger::NONE;
};