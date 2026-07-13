cmake_minimum_required(VERSION 4.1)

project(core-embedded-usb-hid)

set(STM32_HID_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/include/usb/hid/UsbHid.h
        ${CMAKE_CURRENT_LIST_DIR}/src/UsbHid.cpp
)

if(TARGET_PLATFORM STREQUAL "stm32h745i-cm7")
    add_library(core-stm32h745i-cm7-usb-hid STATIC ${STM32_HID_SOURCES})
    target_include_directories(core-stm32h745i-cm7-usb-hid PUBLIC
            ${INCLUDE_DIR}
            ${CMAKE_CURRENT_LIST_DIR}/include
    )
    target_link_libraries(core-stm32h745i-cm7-usb-hid PUBLIC
            core-usb-hid-base
            core-stm32h745i-cm7-tinyusb-host
    )
elseif(TARGET_PLATFORM STREQUAL "stm32h745i-cm4")
    add_library(core-stm32h745i-cm4-usb-hid STATIC ${STM32_HID_SOURCES})
    target_include_directories(core-stm32h745i-cm4-usb-hid PUBLIC
            ${INCLUDE_DIR}
            ${CMAKE_CURRENT_LIST_DIR}/include
    )
    target_link_libraries(core-stm32h745i-cm4-usb-hid PUBLIC
            core-usb-hid-base
            core-stm32h745i-cm4-tinyusb-host
    )
endif()