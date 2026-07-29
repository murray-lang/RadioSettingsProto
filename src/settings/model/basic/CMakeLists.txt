cmake_minimum_required(VERSION 4.1)

project(settings-model-basic)

set(MODEL_BASIC_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/basic/Band.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/basic/WithBandT.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/basic/BandRfSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/basic/BasicActiveBandSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/basic/BasicBandSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/basic/IfSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/basic/Mode.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/basic/WithModeT.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/basic/RfSettingsT.h

        ${CMAKE_CURRENT_LIST_DIR}/src/dummy.cpp
)

add_library(settings-model-basic INTERFACE ${MODEL_BASIC_FILES})

target_include_directories(settings-model-basic INTERFACE
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-basic INTERFACE
        settings-model-base
)