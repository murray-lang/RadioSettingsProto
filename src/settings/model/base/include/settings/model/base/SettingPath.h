#pragma once
#include <cstdint>

#ifdef USE_ETL
#include <etl/vector.h>

using SettingPath = etl::vector<uint32_t, MAX_FIELD_PATH_LENGTH>;
#else
#include <vector>
using SettingPath = std::vector<uint32_t>;
#endif
