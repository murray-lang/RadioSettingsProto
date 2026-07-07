cmake_minimum_required(VERSION 4.1)

project(core-usb-hid-base)

add_library(core-usb-hid-base INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include/usb/hid/base/UsbHidBase.h)

target_include_directories(core-usb-hid-base INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)
target_link_libraries(core-usb-hid-base INTERFACE core-usb-base)