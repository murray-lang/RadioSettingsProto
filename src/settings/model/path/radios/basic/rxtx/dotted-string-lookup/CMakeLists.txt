cmake_minimum_required(VERSION 4.1)

project(settings-model-path-radios-basic-rxtx-lookup)

set(BASIC_RXTX_TAG_LOOKUP_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/path/BasicRxTxTagLookup.h
        ${CMAKE_CURRENT_LIST_DIR}/src/BasicRxTxTagLookup.cpp
)

add_library(settings-model-path-radios-basic-rxtx-lookup STATIC ${BASIC_RXTX_TAG_LOOKUP_FILES})

target_include_directories(settings-model-path-radios-basic-rxtx-lookup PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-path-radios-basic-rxtx-lookup PUBLIC
        settings-model-path-common
)