cmake_minimum_required(VERSION 4.1)

project(ui-qt-property-setter VERSION 0.1 LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

set (QT_PROPERTY_SETTER_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/include/ui/qt/legacy/QWidgetPropertySetter.h
        ${CMAKE_CURRENT_LIST_DIR}/src/QWidgetPropertySetter.cpp
)

add_library(ui-qt-property-setter STATIC ${QT_PROPERTY_SETTER_SOURCES})

target_include_directories(ui-qt-property-setter PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(ui-qt-property-setter PUBLIC
        settings-model-component-common
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
)