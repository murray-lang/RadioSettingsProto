cmake_minimum_required(VERSION 4.1)

project(core-common-dsp-window)

set(DSP_WINDOW_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/include/dsp/window/Window.h
        ${CMAKE_CURRENT_LIST_DIR}/src/Window.cpp
)

add_library(core-common-dsp-window STATIC ${DSP_WINDOW_SOURCES})

target_include_directories(core-common-dsp-window PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

if(USE_ETL)
    target_link_libraries(core-common-dsp-window PUBLIC
            core-common-samples
            core-common-dsp-constants
            etl::etl
    )
else()
    target_link_libraries(core-common-dsp-window PUBLIC
            core-common-samples
            core-common-dsp-constants
    )
endif()