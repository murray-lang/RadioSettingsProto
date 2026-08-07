cmake_minimum_required(VERSION 4.1)

project(settings-model-radio-iq-basic-rxtx)

set(BASIC_RXTX_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radio/iq/BasicIqRxTxSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/src/BasicIqRxTxSettings.cpp
)

add_library(settings-model-radio-iq-basic-rxtx STATIC ${BASIC_RXTX_FILES})

target_include_directories(settings-model-radio-iq-basic-rxtx PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-radio-iq-basic-rxtx PUBLIC
        settings-model-radio-base
        settings-model-component-iq-basic
        settings-model-lookup-radio
)