cmake_minimum_required(VERSION 4.1)

project(settings-model-radio-iq-dual-split)

set(SPLIT_DUAL_IQ_RXTX_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radio/iq/SplitBandDualIqRxTxSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/src/SplitBandDualIqRxTxSettings.cpp
)

add_library(settings-model-radio-iq-dual-split STATIC ${SPLIT_DUAL_IQ_RXTX_FILES})

target_include_directories(settings-model-radio-iq-dual-split PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-radio-iq-dual-split PUBLIC
        settings-model-radio-base
        settings-model-component-iq-dual-split
        settings-model-lookup-radio
)