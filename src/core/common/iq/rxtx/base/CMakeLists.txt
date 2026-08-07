cmake_minimum_required(VERSION 4.1)

project(core-common-iq-rxtx-base)

set(IQ_RXTX_BASE_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/iq/rxtx/IqRxTxBaseT.h
)

add_library(core-common-iq-rxtx-base INTERFACE ${IQ_RXTX_BASE_FILES})

target_include_directories(core-common-iq-rxtx-base INTERFACE
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(core-common-iq-rxtx-base INTERFACE
        core-common-iq-base
        settings-model-radio-iq-basic-rxtx
        config-struct
)