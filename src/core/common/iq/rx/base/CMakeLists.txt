cmake_minimum_required(VERSION 4.1)

project(core-common-iq-rx-base)

set(IQ_RX_BASE_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/iq/rx/IqRxBaseT.h
)

add_library(core-common-iq-rx-base INTERFACE ${IQ_RX_BASE_FILES})

target_include_directories(core-common-iq-rx-base INTERFACE
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(core-common-iq-rx-base INTERFACE
        core-common-iq-base
        core-common-audio
        settings-model-radio-selected
        config-struct
)