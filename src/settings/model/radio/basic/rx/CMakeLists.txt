cmake_minimum_required(VERSION 4.1)

project(settings-model-radio-basic-rx)

set(BASIC_RX_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radio/basic/BasicRxSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/src/BasicRxSettings.cpp
)

add_library(settings-model-radio-basic-rx STATIC ${BASIC_RX_FILES})

target_include_directories(settings-model-radio-basic-rx PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-radio-basic-rx PUBLIC
        settings-model-component-basic
        settings-model-lookup-radio
        settings-model-radio-base
)