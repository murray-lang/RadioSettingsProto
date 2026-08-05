cmake_minimum_required(VERSION 4.1)

project(settings-model-component-iq)

set(MODEL_BASIC_IQ_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/component/BasicIqActiveBandSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/component/BasicIqBandSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/component/IqCorrectionSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/component/PipelineSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/component/PipelineRfSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/component/RxPipelineSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/component/TxPipelineSettings.h
)

add_library(settings-model-component-iq INTERFACE ${MODEL_BASIC_IQ_FILES})

target_include_directories(settings-model-component-iq INTERFACE
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-component-iq INTERFACE
        settings-model-component-basic
)