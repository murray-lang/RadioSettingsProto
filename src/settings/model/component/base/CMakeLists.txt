cmake_minimum_required(VERSION 4.1)

project(settings-model-component-base)

set(COMPONENT_BASE_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/component/AgcSpeed.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/component/Band.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/component/BandRfSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/component/BandSettingsCacheT.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/component/IfSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/component/Mode.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/component/PipelineId.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/component/SplitBandId.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/component/WithBandT.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/component/WithModeT.h
)

add_library(settings-model-component-base INTERFACE ${COMPONENT_BASE_FILES})

target_include_directories(settings-model-component-base INTERFACE
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-component-base INTERFACE
        settings-model-base
        settings-model-proto
)