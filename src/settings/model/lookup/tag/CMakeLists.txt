cmake_minimum_required(VERSION 4.1)

project(settings-model-lookup-tag)

set(SETTINGS_MODEL_LOOKUP_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/lookup/tag/MessageTagLookup.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/lookup/tag/resolveDottedPath.h
        ${CMAKE_CURRENT_LIST_DIR}/src/MessageTagLookup.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/resolveDottedPath.cpp
)

add_library(settings-model-lookup-tag STATIC ${SETTINGS_MODEL_LOOKUP_FILES})

target_include_directories(settings-model-lookup-tag PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-lookup-tag PUBLIC
        settings-model-base
        settings-model-proto
        settings-model-traverse
        etl::etl
)