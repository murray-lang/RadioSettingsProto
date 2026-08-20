cmake_minimum_required(VERSION 4.1)

project(settings-model-path-util-resolve-many)

set(MODEL_UTIL_SOURCES

        include/settings/model/path/generateResolvedPathSourceFiles.h
        src/generateResolvedPathSourceFiles.cpp
)

add_library(settings-model-path-util-resolve-many
        STATIC
        ${MODEL_UTIL_SOURCES}
)

target_include_directories(settings-model-path-util-resolve-many PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-path-util-resolve-many PUBLIC
        settings-model-path-util-resolve-one

)
