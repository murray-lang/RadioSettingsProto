cmake_minimum_required(VERSION 4.1)

project(settings-control-qt-event-targets)
include(${CMAKE_CURRENT_LIST_DIR}/qt.cmake)

set(CMAKE_AUTOMOC ON)

set(QT_EVENT_TARGET_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/control/qt/QtGlobalControlEventTargets.h
        ${CMAKE_CURRENT_LIST_DIR}/src/QtGlobalControlEventTargets.cpp
)

add_library(settings-control-qt-event-targets OBJECT ${QT_EVENT_TARGET_FILES})

target_include_directories(settings-control-qt-event-targets PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-control-qt-event-targets PUBLIC Qt6::Core)