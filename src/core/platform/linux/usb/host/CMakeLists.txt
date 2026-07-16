cmake_minimum_required(VERSION 4.1)

project(core-linux-usb-host)

find_library(HIDAPI_LIBRARY hidapi-libusb)
find_package(USB)
if(NOT USB_FOUND)
    message(FATAL_ERROR "libusb required to compile makesdr")
endif()
if(HIDAPI_LIBRARY)
    MESSAGE(STATUS "System Hidapi Lib ${HIDAPI_LIBRARY} is used")
else()
    MESSAGE(FATAL_ERROR "Hidapi required to compile makesdr")
endif()

set(LINUX_USB_HOST_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/include/usb/host/UsbHost.h
        ${CMAKE_CURRENT_LIST_DIR}/src/UsbHost.cpp
        ${CMAKE_CURRENT_LIST_DIR}/include/usb/host/UsbHidHost.h
        ${CMAKE_CURRENT_LIST_DIR}/src/UsbHidHost.cpp
)

add_library(core-linux-usb-host ${LINUX_USB_HOST_SOURCES})
target_include_directories(core-linux-usb-host PUBLIC
        ${INCLUDE_DIR}
        /usr/include/hidapi/
        ${CMAKE_CURRENT_LIST_DIR}/include
)
target_link_libraries(core-linux-usb-host PUBLIC
        core-usb-base
        usb-1.0
        hidapi-libusb
)