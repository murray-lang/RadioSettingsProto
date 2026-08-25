cmake_minimum_required(VERSION 4.1)

project(ui-qt-charts-timeseries VERSION 0.1 LANGUAGES CXX)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Charts)

set (QT_TIMESERIES_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/include/ui/qt/legacy/charts/QtTimeSeriesChart.h
        ${CMAKE_CURRENT_LIST_DIR}/src/QtTimeSeriesChart.cpp
)

add_library(ui-qt-charts-timeseries STATIC ${QT_TIMESERIES_SOURCES})

target_include_directories(ui-qt-charts-timeseries PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(ui-qt-charts-timeseries PUBLIC
        ui-qt-charts-base
        settings-model-component-common
)