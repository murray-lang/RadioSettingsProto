cmake_minimum_required(VERSION 4.1)

project(core-common-dsp-constants)

set(DSP_CONST_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/dsp/constants/constants.h
)

add_library(core-common-dsp-constants INTERFACE ${DSP_CONST_FILES})

target_include_directories(core-common-dsp-constants INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/include
)
