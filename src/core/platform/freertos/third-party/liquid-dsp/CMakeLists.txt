cmake_minimum_required(VERSION 4.1)

project(core-freertos-liquid-dsp)

set(BUILD_EXAMPLES OFF)
set(BUILD_AUTOTESTS OFF)
set(BUILD_BENCHMARKS OFF)
set(BUILD_SHARED_LIBS OFF)
set(BUILD_STATIC_LIBS ON)
set(FIND_FFTW OFF)
set(ENABLE_LOGGING OFF)

add_subdirectory(${LIQUID_DSP_DIR} ${CMAKE_BINARY_DIR}/freertos-liquid-dsp-${TARGET_PLATFORM})

set(LIQUID_OVERRIDE_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/src/liquid_freertos_calloc.c
)

add_library(core-freertos-liquid-dsp STATIC ${LIQUID_OVERRIDE_SOURCES})

target_compile_definitions(core-freertos-liquid-dsp PRIVATE
        malloc=pvPortMalloc
        calloc=liquid_freertos_calloc  # Custom wrapper needed because FreeRTOS lacks pPortCalloc
        free=vPortFree
)

target_include_directories(core-freertos-liquid-dsp PUBLIC
        ${LIQUID_DSP_DIR}/include
        ${CMAKE_BINARY_DIR}/freertos-liquid-dsp-${TARGET_PLATFORM}
)

if(TARGET_PLATFORM STREQUAL "stm32h745i-cm7")
    target_link_libraries(core-freertos-liquid-dsp PUBLIC
            core-stm32h745i-cm7-freertos
            liquid
    )
elseif(TARGET_PLATFORM STREQUAL "stm32h745i-cm4")
    target_link_libraries(core-freertos-liquid-dsp PUBLIC
            core-stm32h745i-cm4-freertos
            liquid
    )
endif()