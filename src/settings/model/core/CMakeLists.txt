cmake_minimum_required(VERSION 4.1)

project(settings-model-core)

set(CORE_SETTINGS_SOURCES
        include/settings/model/core/BandSettingsCache.h
        include/settings/model/core/PipelineId.h
        include/settings/model/core/RadioPayloadBase.h
        include/settings/model/core/RadioSettings.h
        include/settings/model/core/RadioSettingsSink.h
        include/settings/model/core/RadioSettingsSource.h
        include/settings/model/core/SplitBandId.h


        src/BandSettingsCache.cpp
        src/RadioSettings.cpp
)

add_library(settings-model-core STATIC ${CORE_SETTINGS_SOURCES})

target_include_directories(settings-model-core PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-core PUBLIC
        settings-model-proto
        settings-model-base
        settings-model-traverse
        settings-model-meta
        # core-stm32h745i-app-support-cm4
        # core-stm32h745i-drivers-bsp-disco-cm4
        etl
)