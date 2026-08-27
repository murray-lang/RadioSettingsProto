cmake_minimum_required(VERSION 4.1)

project(ui-qt-radio-client)

find_package(Qt6 REQUIRED COMPONENTS Core)

set(QT_RADIO_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/ui/qt/QtRadioClient.h
        ${CMAKE_CURRENT_LIST_DIR}/src/QtRadioClient.cpp
)

add_library(ui-qt-radio-client STATIC ${QT_RADIO_FILES})

target_include_directories(ui-qt-radio-client PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(ui-qt-radio-client PUBLIC
        Qt6::Core
        radios-base
        core-common-samples
        core-linux-event-data
        core-linux-event-targets
        settings-control-qt-event-targets
        settings-model-path-radios-update-helpers
)
