cmake_minimum_required(VERSION 4.1)

project(ui-qt-util VERSION 0.1 LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Charts)

set (QT_UTIL_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/include/ui/qt/util/QtUtil.h
        ${CMAKE_CURRENT_LIST_DIR}/src/QtUtil.cpp
)

add_library(ui-qt-util STATIC ${QT_UTIL_SOURCES})

target_include_directories(ui-qt-util PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(ui-qt-util PUBLIC
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        config-json
)