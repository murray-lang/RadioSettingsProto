cmake_minimum_required(VERSION 4.1)

project(settings-model-basic-iq-rxtx)

set(BASIC_RXTX_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/iq/BasicIqRxTxSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/src/BasicIqRxTxSettings.cpp
)

add_library(settings-model-basic-iq-rxtx STATIC ${BASIC_RXTX_FILES})

target_include_directories(settings-model-basic-iq-rxtx PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-basic-iq-rxtx PUBLIC
        settings-model-basic-iq-components
        settings-model-lookup-radio
)