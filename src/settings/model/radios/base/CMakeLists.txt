cmake_minimum_required(VERSION 4.1)

project(settings-model-radios-base)

set(RADIOS_BASE_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/base/RadioSettingsBaseT.h
)

add_library(settings-model-radios-base INTERFACE ${RADIOS_BASE_FILES})

target_include_directories(settings-model-radios-base INTERFACE
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-radios-base INTERFACE
        settings-model-proto
        settings-model-base
        settings-model-traverse
        settings-model-data-radio
)