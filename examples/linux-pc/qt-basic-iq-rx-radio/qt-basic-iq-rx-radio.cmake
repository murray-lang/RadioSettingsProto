cmake_minimum_required(VERSION 4.1)

project(example-qt-basic-iq-rx-radio VERSION 0.1 LANGUAGES CXX)

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
        radio-basic-iq-rx
        etl::etl
)