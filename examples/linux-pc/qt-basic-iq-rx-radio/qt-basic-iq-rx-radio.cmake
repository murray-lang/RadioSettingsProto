cmake_minimum_required(VERSION 4.1)

project(example-qt-basic-iq-rx-radio VERSION 0.1 LANGUAGES CXX)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui Widgets Charts)

set (PROJECT_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/main.cpp
)

add_executable(example-qt-basic-iq-rx-radio
        ${PROJECT_SOURCES}
)

target_include_directories(example-qt-basic-iq-rx-radio PUBLIC
        ${INCLUDE_DIR}
)

target_link_libraries(example-qt-basic-iq-rx-radio PUBLIC
        config-json
        settings-model-radio-selected
        radio-basic-iq-rx
        core-linux-audio
        etl::etl
        Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Gui
        Qt${QT_VERSION_MAJOR}::Widgets
        ArduinoJson
)