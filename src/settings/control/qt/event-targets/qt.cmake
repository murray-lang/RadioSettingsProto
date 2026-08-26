cmake_minimum_required(VERSION 4.1)

list(APPEND CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")

find_package(PkgConfig)

find_package(Qt6 REQUIRED COMPONENTS Core)
if(QT_FOUND)
    message("Qt found")
else()
    message("Qt NOT found")
endif()
