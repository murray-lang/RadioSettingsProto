cmake_minimum_required(VERSION 4.1)

project(settings-model-radio-iq-dual-rx)

set(DUAL_IQ_RX_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radio/iq/DualIqRxSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/src/DualIqRxSettings.cpp
)

add_library(settings-model-radio-iq-dual-rx STATIC ${DUAL_IQ_RX_FILES})

target_include_directories(settings-model-radio-iq-dual-rx PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-radio-iq-dual-rx PUBLIC
        settings-model-radio-base
        settings-model-component-iq-dual-rx
        settings-model-lookup-radio
)