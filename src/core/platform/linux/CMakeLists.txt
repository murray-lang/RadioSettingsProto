cmake_minimum_required(VERSION 4.1)

project(core-linux)

if(USE_GPIO)
    add_subdirectory(gpio)
endif()
add_subdirectory(usb)
add_subdirectory(thread)
add_subdirectory(time)
