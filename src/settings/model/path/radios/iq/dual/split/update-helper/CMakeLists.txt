cmake_minimum_required(VERSION 4.1)

project(settings-model-path-radios-dual-iq-split-helper)

set(DUAL_IQ_SPLIT_RESOLVED_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/update/SplitBandDualIqUpdateHelper.h
        ${CMAKE_CURRENT_LIST_DIR}/src/SplitBandDualIqUpdateHelper.cpp
)

add_library(settings-model-path-radios-dual-iq-split-helper STATIC ${DUAL_IQ_SPLIT_RESOLVED_FILES})

target_include_directories(settings-model-path-radios-dual-iq-split-helper PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-path-radios-dual-iq-split-helper PUBLIC
        settings-model-radios-base
        settings-model-path-radios-dual-iq-split-resolved
)