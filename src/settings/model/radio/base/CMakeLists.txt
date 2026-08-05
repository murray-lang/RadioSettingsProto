
cmake_minimum_required(VERSION 4.1)

project(settings-model-radio-base)

set(MODEL_RADIO_BASE_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radio/base/RadioSettingsBaseT.h
)

add_library(settings-model-radio-base INTERFACE ${MODEL_RADIO_BASE_FILES})

target_include_directories(settings-model-radio-base INTERFACE
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-radio-base INTERFACE
        settings-model-traverse
        settings-model-lookup-radio
)