cmake_minimum_required(VERSION 4.1)

project(ui-qt-mini-vfo-toolbar VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

set (QT_UTIL_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/include/ui/qt/legacy/QtMiniVfoToolbar.h
        ${CMAKE_CURRENT_LIST_DIR}/src/QtMiniVfoToolbar.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/QtMiniVfoToolbar.ui
)

add_library(ui-qt-mini-vfo-toolbar STATIC ${QT_UTIL_SOURCES})

target_include_directories(ui-qt-mini-vfo-toolbar PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(ui-qt-mini-vfo-toolbar PUBLIC
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        config-json
        settings-model-base
        ui-qt-property-setter
)