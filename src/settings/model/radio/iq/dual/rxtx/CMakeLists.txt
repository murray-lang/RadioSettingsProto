cmake_minimum_required(VERSION 4.1)

project(settings-model-radio-iq-dual-rxtx)

set(DUAL_IQ_RXTX_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radio/iq/DualIqRxTxSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/src/DualIqRxTxSettings.cpp
)

add_library(settings-model-radio-iq-dual-rxtx STATIC ${DUAL_IQ_RXTX_FILES})

target_include_directories(settings-model-radio-iq-dual-rxtx PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-radio-iq-dual-rxtx PUBLIC
        settings-model-radio-base
        settings-model-component-iq-dual-rxtx
        settings-model-lookup-radio
)