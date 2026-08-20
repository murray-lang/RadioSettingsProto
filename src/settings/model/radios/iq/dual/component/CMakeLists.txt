cmake_minimum_required(VERSION 4.1)

project(settings-model-radios-iq-dual-component)

set(MODEL_DUAL_IQ_COMPONENT_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/component/DualIqActiveBandSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/component/DualIqBandSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/component/RxTxDualIqActiveBandSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/component/RxTxDualIqBandSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/component/SplitBandDualIqActiveBandSettings.h

        ${CMAKE_CURRENT_LIST_DIR}/src/DualIqActiveBandSettings.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/DualIqBandSettings.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/RxTxDualIqActiveBandSettings.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/RxTxDualIqBandSettings.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/SplitBandDualIqActiveBandSettings.cpp
)

add_library(settings-model-radios-iq-dual-component STATIC ${MODEL_DUAL_IQ_COMPONENT_FILES})

target_include_directories(settings-model-radios-iq-dual-component PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-radios-iq-dual-component PUBLIC
        settings-model-radios-iq-basic-component
)