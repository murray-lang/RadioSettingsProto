cmake_minimum_required(VERSION 4.1)

project(core-common-iq-rx-basic)

set(IQ_RX_BASIC_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/iq/rx/BasicIqRx.h
        ${CMAKE_CURRENT_LIST_DIR}/src/BasicIqRx.cpp
)

add_library(core-common-iq-rx-basic STATIC ${IQ_RX_BASIC_FILES})

target_include_directories(core-common-iq-rx-basic PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(core-common-iq-rx-basic PUBLIC
        core-common-iq-rx-base
        core-common-iq-pipeline-rx
        core-common-iq-io
        settings-model-radio-iq-basic-rx

)