cmake_minimum_required(VERSION 4.1)

project(settings-control-hal-usb-sinks)

set(USB_CONTROL_SOURCES
        include/settings/control/usb/sinks/UsbControlSinkFactoryT.h
        include/settings/control/usb/sinks/UsbControlSinksT.h
        include/settings/control/usb/sinks/UsbControlSinkTypesT.h
)

add_library(settings-control-hal-usb-sinks INTERFACE ${USB_CONTROL_SOURCES})
target_include_directories(settings-control-hal-usb-sinks INTERFACE
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-control-hal-usb-sinks INTERFACE
        settings-control-hal-usb-funcube
        settings-control-hal-usb-softrock
)