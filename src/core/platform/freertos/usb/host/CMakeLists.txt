cmake_minimum_required(VERSION 4.1)

project(core-freertos-usb-host)

set(FREERTOS_USB_HOST_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/include/usb/host/UsbHidHost.h
        ${CMAKE_CURRENT_LIST_DIR}/include/usb/host/UsbHost.h
        ${CMAKE_CURRENT_LIST_DIR}/src/UsbHidHost.cpp
        ${CMAKE_CURRENT_LIST_DIR}/include/usb/host/UsbHostThread.h

        ${CMAKE_CURRENT_LIST_DIR}/src/UsbHost.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/UsbHostThread.cpp
)

add_library(core-freertos-usb-host STATIC ${FREERTOS_USB_HOST_SOURCES})
target_include_directories(core-freertos-usb-host PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

if(TARGET_PLATFORM STREQUAL "stm32h745i-cm7")
    target_link_libraries(core-freertos-usb-host PUBLIC
            core-usb-base
            core-stm32h745i-cm7-tinyusb-host
            core-freertos-thread
            etl::etl
    )
elseif(TARGET_PLATFORM STREQUAL "stm32h745i-cm4")
    target_link_libraries(core-freertos-usb-host PUBLIC
            core-usb-base
            core-stm32h745i-cm4-tinyusb-host
            core-freertos-thread
            etl::etl
            core-stm32h745i-drivers-bsp-disco-cm4
    )
endif()