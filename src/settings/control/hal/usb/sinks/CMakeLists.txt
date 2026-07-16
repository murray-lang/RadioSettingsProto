cmake_minimum_required(VERSION 4.1)

project(settings-control-hal-usb-sinks)

set(USB_CONTROL_SOURCES
        include/settings/control/usb/sinks/UsbControlSinks.h
        include/settings/control/usb/sinks/UsbControlSinkTypes.h

        src/UsbControlSinkFactory.cpp
        src/UsbControlSinks.cpp
)

add_library(settings-control-hal-usb-sinks STATIC ${USB_CONTROL_SOURCES})
target_include_directories(settings-control-hal-usb-sinks PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-control-hal-usb-sinks PUBLIC
        settings-control-hal-usb-funcube
        settings-control-hal-usb-softrock
)