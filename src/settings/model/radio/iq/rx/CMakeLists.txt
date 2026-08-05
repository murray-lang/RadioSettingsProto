cmake_minimum_required(VERSION 4.1)

project(settings-model-radio-iq-rx)

set(BASIC_RX_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radio/iq/BasicIqRxSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/src/BasicIqRxSettings.cpp
)

add_library(settings-model-radio-iq-rx STATIC ${BASIC_RX_FILES})

target_include_directories(settings-model-radio-iq-rx PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-radio-iq-rx PUBLIC
        settings-model-radio-base
        settings-model-component-iq
        settings-model-lookup-radio
)