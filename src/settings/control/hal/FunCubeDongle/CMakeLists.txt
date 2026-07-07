cmake_minimum_required(VERSION 4.1)

project(settings-control-hal-funcube)

set(FUNCUBE_SOURCES
        include/settings/control/FunCubeDongle/FCDHidCmd.h
        include/settings/control/FunCubeDongle/FunCubeDongle.h
        src/FunCubeDongle.cpp
)

set(FUNCUBE_LIBS
        config-struct
        settings-control-base
        settings-control-sink
        settings-model-core
)

if (PLATFORM_FAMILY STREQUAL "linux")
    set(FUNCUBE_LIBS ${FUNCUBE_LIBS} core-linux-usb-hid)
endif()

add_library(settings-control-hal-funcube STATIC ${FUNCUBE_SOURCES})

target_include_directories(settings-control-hal-funcube PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-control-hal-funcube PUBLIC ${FUNCUBE_LIBS})