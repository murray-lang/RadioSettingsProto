cmake_minimum_required(VERSION 4.1)

project(core-common-iq-common)

set(IQ_COMMON_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/include/iq/common/IqTransmitter.h
        ${CMAKE_CURRENT_LIST_DIR}/src/IqTransmitter.cpp
)

add_library(core-common-iq-common STATIC ${IQ_COMMON_SOURCES})
target_include_directories(core-common-iq-common PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)
target_link_libraries(core-common-iq-common PUBLIC
        core-common-samples
        config-struct
        core-common-iq-io
        core-common-iq-pipeline-tx
)