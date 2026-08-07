cmake_minimum_required(VERSION 4.1)

project(settings-model-component-basic)

set(MODEL_BASIC_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/component/BasicActiveBandSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/component/BasicBandSettings.h

        ${CMAKE_CURRENT_LIST_DIR}/src/BasicActiveBandSettings.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/BasicBandSettings.cpp
)

add_library(settings-model-component-basic STATIC ${MODEL_BASIC_FILES})

target_include_directories(settings-model-component-basic PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-component-basic PUBLIC
        settings-model-component-base
        settings-model-proto
)