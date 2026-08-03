cmake_minimum_required(VERSION 4.1)

project(settings-model-radios-basic-rx)

set(BASIC_RX_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/basic/BasicRxSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/src/BasicRxSettings.cpp
)

add_library(settings-model-radios-basic-rx STATIC ${BASIC_RX_FILES})

target_include_directories(settings-model-radios-basic-rx PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-radios-basic-rx PUBLIC
        settings-model-basic
        settings-model-lookup-radio
)