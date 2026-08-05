cmake_minimum_required(VERSION 4.1)

project(core-common-dsp-transforms-fft-liquid)

set(LIQUID_FFT_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/include/dsp/transforms/fft/Fft.h
        ${CMAKE_CURRENT_LIST_DIR}/src/Fft.cpp
)

add_library(core-common-dsp-transforms-fft-liquid STATIC ${LIQUID_FFT_SOURCES})

target_include_directories(core-common-dsp-transforms-fft-liquid PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

if(USE_FREERTOS)
    target_link_libraries(core-common-dsp-transforms-fft-liquid PUBLIC
            core-common-dsp-transforms-fft-base
            core-freertos-liquid-dsp
    )
else()
    target_link_libraries(core-common-dsp-transforms-fft-liquid PUBLIC
            core-common-dsp-transforms-fft-base
            core-linux-liquid-dsp
    )
endif()