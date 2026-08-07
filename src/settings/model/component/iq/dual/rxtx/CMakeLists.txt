cmake_minimum_required(VERSION 4.1)

project(settings-model-component-iq-dual-rxtx)

set(MODEL_RXTX_DUAL_IQ_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/component/RxTxDualIqActiveBandSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/component/RxTxDualIqBandSettings.h

        ${CMAKE_CURRENT_LIST_DIR}/src/RxTxDualIqActiveBandSettings.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/RxTxDualIqBandSettings.cpp
)

add_library(settings-model-component-iq-dual-rxtx STATIC ${MODEL_RXTX_DUAL_IQ_FILES})

target_include_directories(settings-model-component-iq-dual-rxtx PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-component-iq-dual-rxtx PUBLIC
        settings-model-component-iq-basic
)