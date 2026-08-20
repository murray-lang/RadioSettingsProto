cmake_minimum_required(VERSION 4.1)

project(settings-model-path-radios-dual-iq-split-helpers)

set(DUAL_IQ_SPLIT_RESOLVED_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/update/SplitBandDualIqUpdateHelpers.h
        ${CMAKE_CURRENT_LIST_DIR}/src/SplitBandDualIqUpdateHelpers.cpp
)

add_library(settings-model-path-radios-dual-iq-split-helpers STATIC ${DUAL_IQ_SPLIT_RESOLVED_FILES})

target_include_directories(settings-model-path-radios-dual-iq-split-helpers PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-path-radios-dual-iq-split-helpers PUBLIC
        settings-model-radios-common-component
        settings-model-path-radios-dual-iq-split-resolved
)