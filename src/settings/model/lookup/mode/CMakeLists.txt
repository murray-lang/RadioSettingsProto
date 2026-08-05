cmake_minimum_required(VERSION 4.1)

project(settings-model-lookup-mode)

set(MODE_LOOKUP_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/lookup/mode/basicModes.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/lookup/mode/ModeList.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/lookup/mode/ModeTypes.h

        ${CMAKE_CURRENT_LIST_DIR}/src/basicModes.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/ModeList.cpp
)

add_library(settings-model-lookup-mode STATIC ${MODE_LOOKUP_FILES})

target_include_directories(settings-model-lookup-mode PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-lookup-mode PUBLIC
        settings-model-proto
        etl::etl
)