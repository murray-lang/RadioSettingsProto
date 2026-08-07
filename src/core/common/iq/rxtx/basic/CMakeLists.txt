cmake_minimum_required(VERSION 4.1)

project(core-common-iq-rxtx-basic)

set(IQ_RXTX_BASIC_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/iq/rxtx/BasicIqRxTx.h
        ${CMAKE_CURRENT_LIST_DIR}/src/BasicIqRxTx.cpp
)

add_library(core-common-iq-rxtx-basic STATIC ${IQ_RXTX_BASIC_FILES})

target_include_directories(core-common-iq-rxtx-basic PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(core-common-iq-rxtx-basic PUBLIC
        core-common-iq-rxtx-base
        core-common-iq-pipeline-rx
        core-common-iq-pipeline-tx
        core-common-iq-io
        settings-model-radio-iq-basic-rxtx

)