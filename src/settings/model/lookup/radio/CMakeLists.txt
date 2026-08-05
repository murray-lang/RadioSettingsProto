cmake_minimum_required(VERSION 4.1)

project(settings-model-lookup-radio)

set(SETTINGS_MODEL_LOOKUP_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/lookup/radio/generalCoverageRadioLookup.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/lookup/radio/RadioLookup.h
        ${CMAKE_CURRENT_LIST_DIR}/src/generalCoverageRadioLookup.cpp
)

add_library(settings-model-lookup-radio STATIC ${SETTINGS_MODEL_LOOKUP_FILES})

target_include_directories(settings-model-lookup-radio PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-lookup-radio PUBLIC
        settings-model-lookup-band
        settings-model-lookup-mode
)