cmake_minimum_required(VERSION 4.1)

project(settings-model-radios-common-component)

set(COMPONENT_BASE_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/component/AfSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/component/AgcSpeed.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/component/Band.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/component/BandRfSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/component/BandSettingsCacheT.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/component/IActiveBandSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/component/IBandSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/component/IfSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/component/Mode.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/component/PipelineId.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/component/ReceiverSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/component/SplitBandId.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/component/TransmitterSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/component/WithBandT.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/component/WithModeT.h

        ${CMAKE_CURRENT_LIST_DIR}/src/Band.cpp
)

add_library(settings-model-radios-common-component STATIC ${COMPONENT_BASE_FILES})

target_include_directories(settings-model-radios-common-component PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-radios-common-component PUBLIC
        settings-model-base
        settings-model-proto
        settings-model-data-radio
)