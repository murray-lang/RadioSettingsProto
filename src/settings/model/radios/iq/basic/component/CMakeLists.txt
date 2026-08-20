cmake_minimum_required(VERSION 4.1)

project(settings-model-radios-iq-basic-component)

set(MODEL_BASIC_IQ_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/component/BasicIqActiveBandSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/component/BasicIqBandSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/component/IqCorrectionSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/component/PipelineSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/component/PipelineRfSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/component/RxPipelineSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/component/TxPipelineSettings.h

        ${CMAKE_CURRENT_LIST_DIR}/src/BasicIqActiveBandSettings.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/BasicIqBandSettings.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/IqCorrectionSettings.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/PipelineSettings.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/PipelineRfSettings.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/RxPipelineSettings.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/TxPipelineSettings.cpp
)

add_library(settings-model-radios-iq-basic-component STATIC ${MODEL_BASIC_IQ_FILES})

target_include_directories(settings-model-radios-iq-basic-component PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-radios-iq-basic-component PUBLIC
        settings-model-radios-common-component
#        settings-model-radios-basic-component
)