cmake_minimum_required(VERSION 4.1)

project(settings-model-component-iq-dual-split)

set(MODEL_SPLIT_IQ_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/component/SplitBandDualIqActiveBandSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/src/SplitBandDualIqActiveBandSettings.cpp
)

add_library(settings-model-component-iq-dual-split STATIC ${MODEL_SPLIT_IQ_FILES})

target_include_directories(settings-model-component-iq-dual-split PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-component-iq-dual-split PUBLIC
        settings-model-component-iq-dual-rxtx
)