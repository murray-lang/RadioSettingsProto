cmake_minimum_required(VERSION 4.1)

project(ui-qt-legacy-vfo-readout VERSION 0.1 LANGUAGES CXX)

#find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

set (QT_VFO_READOUT_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/include/ui/qt/legacy/QtVfoReadout.h
        ${CMAKE_CURRENT_LIST_DIR}/include/ui/qt/legacy/VfoActions.h
        ${CMAKE_CURRENT_LIST_DIR}/src/QtVfoReadout.cpp
)

add_library(ui-qt-legacy-vfo-readout STATIC ${QT_VFO_READOUT_SOURCES})

target_include_directories(ui-qt-legacy-vfo-readout PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(ui-qt-legacy-vfo-readout PUBLIC
        ui-qt-legacy-number-readout
        ui-qt-legacy-mini-vfo-toolbar
        settings-model-radios-selected
        settings-model-component-common
)