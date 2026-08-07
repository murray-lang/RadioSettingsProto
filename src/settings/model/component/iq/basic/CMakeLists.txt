cmake_minimum_required(VERSION 4.1)

project(settings-model-component-iq-basic)

set(MODEL_BASIC_IQ_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/component/BasicIqActiveBandSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/component/BasicIqBandSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/component/IqCorrectionSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/component/PipelineSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/component/PipelineRfSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/component/RxPipelineSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/component/TxPipelineSettings.h

        ${CMAKE_CURRENT_LIST_DIR}/src/BasicIqActiveBandSettings.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/BasicIqBandSettings.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/IqCorrectionSettings.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/PipelineSettings.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/PipelineRfSettings.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/RxPipelineSettings.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/TxPipelineSettings.cpp
)

add_library(settings-model-component-iq-basic STATIC ${MODEL_BASIC_IQ_FILES})

target_include_directories(settings-model-component-iq-basic PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-component-iq-basic PUBLIC
        settings-model-component-basic
)