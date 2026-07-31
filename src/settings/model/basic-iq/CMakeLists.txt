cmake_minimum_required(VERSION 4.1)

project(settings-model-basic-iq)

set(MODEL_BASIC_IQ_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/basic-iq/IqCorrectionSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/basic-iq/PipelineSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/basic-iq/PipelineRfSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/basic-iq/RxPipelineSettings.h

        ${CMAKE_CURRENT_LIST_DIR}/src/dummy.cpp
)

add_library(settings-model-basic-iq INTERFACE ${MODEL_BASIC_IQ_FILES})

target_include_directories(settings-model-basic-iq INTERFACE
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-basic-iq INTERFACE
        settings-model-basic
)