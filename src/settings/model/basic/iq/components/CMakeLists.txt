cmake_minimum_required(VERSION 4.1)

project(settings-model-basic-iq-components)

set(MODEL_BASIC_IQ_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/iq/IqCorrectionSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/iq/PipelineSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/iq/PipelineRfSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/iq/RxPipelineSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/iq/TxPipelineSettings.h

        ${CMAKE_CURRENT_LIST_DIR}/src/dummy.cpp
)

add_library(settings-model-basic-iq-components INTERFACE ${MODEL_BASIC_IQ_FILES})

target_include_directories(settings-model-basic-iq-components INTERFACE
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-basic-iq-components INTERFACE
        settings-model-basic-components
)