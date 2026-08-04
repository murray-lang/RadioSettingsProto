cmake_minimum_required(VERSION 4.1)

project(radio-basic-iq-rx)

set(RADIO_IQ_RX_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/radio/iq/rx/BasicIqRxRadio.h
        ${CMAKE_CURRENT_LIST_DIR}/src/BasicIqRxRadio.cpp
)

add_library(radio-basic-iq-rx STATIC ${RADIO_IQ_RX_FILES})

target_include_directories(radio-basic-iq-rx PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(radio-basic-iq-rx PUBLIC
        core-common-iq-rx-basic
        settings-control-radio
)