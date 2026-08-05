cmake_minimum_required(VERSION 4.1)

project(core-common-dsp-transforms-hilbert)

set(TRANSFORM_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/include/dsp/transforms/hilbert/HilbertTransform.h
        ${CMAKE_CURRENT_LIST_DIR}/src/HilbertTransform.cpp
)

add_library(core-common-dsp-transforms-hilbert STATIC ${TRANSFORM_SOURCES})

target_include_directories(core-common-dsp-transforms-hilbert PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

if(USE_FREERTOS)
    target_link_libraries(core-common-dsp-transforms-hilbert PUBLIC
            core-common-samples
            core-freertos-liquid-dsp
    )
else()
    target_link_libraries(core-common-dsp-transforms-hilbert PUBLIC
            core-common-samples
            core-linux-liquid-dsp
    )
endif()