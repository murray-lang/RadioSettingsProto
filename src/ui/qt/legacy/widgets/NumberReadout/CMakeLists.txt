cmake_minimum_required(VERSION 4.1)

project(ui-qt-legacy-number-readout VERSION 0.1 LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

set (QT_NUMBER_READOUT_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/include/ui/qt/legacy/QtNumberReadout.h
        ${CMAKE_CURRENT_LIST_DIR}/src/QtNumberReadout.cpp
)

add_library(ui-qt-legacy-number-readout STATIC ${QT_NUMBER_READOUT_SOURCES})

target_include_directories(ui-qt-legacy-number-readout PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(ui-qt-legacy-number-readout PUBLIC
        settings-model-component-common
        core-common-samples
        ui-qt-legacy-property-setter
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
)