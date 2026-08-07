cmake_minimum_required(VERSION 4.1)

project(settings-model-component-iq-dual-rx)

set(MODEL_DUAL_IQ_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/component/DualIqActiveBandSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/component/DualIqBandSettings.h

        ${CMAKE_CURRENT_LIST_DIR}/src/DualIqActiveBandSettings.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/DualIqBandSettings.cpp
)

add_library(settings-model-component-iq-dual-rx STATIC ${MODEL_DUAL_IQ_FILES})

target_include_directories(settings-model-component-iq-dual-rx PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-component-iq-dual-rx PUBLIC
        settings-model-component-iq-basic
)