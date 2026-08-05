cmake_minimum_required(VERSION 4.1)

project(radio-base)

set(RADIO_BASE_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/radio/base/RadioBase.h
)

add_library(radio-base INTERFACE ${RADIO_BASE_FILES})

target_include_directories(radio-base INTERFACE
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(radio-base INTERFACE
        settings-model-radio-selected
        settings-control-sink
)