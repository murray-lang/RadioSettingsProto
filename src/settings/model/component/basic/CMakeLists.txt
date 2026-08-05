cmake_minimum_required(VERSION 4.1)

project(settings-model-component-basic)

set(MODEL_BASIC_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/component/BasicActiveBandSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/component/BasicBandSettings.h
)

add_library(settings-model-component-basic INTERFACE ${MODEL_BASIC_FILES})

target_include_directories(settings-model-component-basic INTERFACE
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-component-basic INTERFACE
        settings-model-component-base
        settings-model-proto
)