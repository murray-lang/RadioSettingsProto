cmake_minimum_required(VERSION 4.1)

project(settings-model-radios-basic-component)

set(MODEL_BASIC_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/component/BasicActiveBandSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/component/BasicBandSettings.h

        ${CMAKE_CURRENT_LIST_DIR}/src/BasicActiveBandSettings.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/BasicBandSettings.cpp
)

add_library(settings-model-radios-basic-component STATIC ${MODEL_BASIC_FILES})

target_include_directories(settings-model-radios-basic-component PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-radios-basic-component PUBLIC
        settings-model-radios-common-component
        settings-model-proto
)