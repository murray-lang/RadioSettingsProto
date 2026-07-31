cmake_minimum_required(VERSION 4.1)

project(core-common-dsp-transforms-fft-pocket)

set(TRANSFORM_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/include/dsp/transforms/fft/Fft.h
        ${CMAKE_CURRENT_LIST_DIR}/src/Fft.cpp
)

add_library(core-common-dsp-transforms-fft-pocket STATIC ${TRANSFORM_SOURCES})

target_include_directories(core-common-dsp-transforms-fft-pocket PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(core-common-dsp-transforms-fft-pocket PUBLIC
        core-common-dsp-transforms-fft-base
)
