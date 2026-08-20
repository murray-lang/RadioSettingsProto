cmake_minimum_required(VERSION 4.1)

project(radios-iq-dual-split)

set(DUAL_SPLIT_RADIO_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/radios/iq/SplitBandDualIqRadio.h
        ${CMAKE_CURRENT_LIST_DIR}/src/SplitBandDualIqRadio.cpp
)

add_library(radios-iq-dual-split STATIC ${DUAL_SPLIT_RADIO_FILES})

target_include_directories(radios-iq-dual-split PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(radios-iq-dual-split PUBLIC
        radios-base
        core-common-iq-dual-split
        settings-control-radio
        settings-model-radios-iq-dual-split
)