cmake_minimum_required(VERSION 4.1)

project(ui-qt-charts-panadapter VERSION 0.1 LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Charts)

set (QT_PANADAPTER_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/include/ui/qt/legacy/charts/QtPanadapter.h
        ${CMAKE_CURRENT_LIST_DIR}/src/QtPanadapter.cpp
)

add_library(ui-qt-charts-panadapter STATIC ${QT_PANADAPTER_SOURCES})

target_include_directories(ui-qt-charts-panadapter PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(ui-qt-charts-panadapter PUBLIC
        ui-qt-charts-base
        core-common-dsp-transforms-fft-liquid
)