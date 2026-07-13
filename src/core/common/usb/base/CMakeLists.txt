cmake_minimum_required(VERSION 4.1)

project(core-usb-base)

add_library(core-usb-base INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include/usb/base/UsbBase.h)

target_include_directories(core-usb-base INTERFACE
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)
