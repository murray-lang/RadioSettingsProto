cmake_minimum_required(VERSION 4.1)

project(settings-model-traverse)

set(TRAVERSER_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/traverse/MessageTraverser.h
        ${CMAKE_CURRENT_LIST_DIR}/src/MessageTraverser.cpp
)

add_library(settings-model-traverse STATIC ${TRAVERSER_SOURCES})

target_include_directories(settings-model-traverse PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-traverse PUBLIC
        settings-model-proto
        settings-model-base
        etl::etl
)