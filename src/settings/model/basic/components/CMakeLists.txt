cmake_minimum_required(VERSION 4.1)

project(settings-model-basic-components)

set(MODEL_BASIC_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/basic/WithBandT.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/basic/BasicActiveBandSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/basic/BasicBandSettings.h

        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/basic/WithModeT.h

        ${CMAKE_CURRENT_LIST_DIR}/src/dummy.cpp
)

add_library(settings-model-basic-components INTERFACE ${MODEL_BASIC_FILES})

target_include_directories(settings-model-basic-components INTERFACE
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-basic-components INTERFACE
        settings-model-base
)