cmake_minimum_required(VERSION 4.1)

project(core-common-dsp-transforms-fft-base)

set(BASE_FFT_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/include/dsp/transforms/fft/FftBase.h
        ${CMAKE_CURRENT_LIST_DIR}/src/FftBase.cpp
)

add_library(core-common-dsp-transforms-fft-base STATIC ${BASE_FFT_SOURCES})

target_include_directories(core-common-dsp-transforms-fft-base PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

if(USE_ETL)
    target_link_libraries(core-common-dsp-transforms-fft-base PUBLIC
            core-common-samples
            core-common-dsp-window
            etl::etl
    )
else()
    target_link_libraries(core-common-dsp-transforms-fft-base PUBLIC
            core-common-samples
            core-common-dsp-window
    )
endif()