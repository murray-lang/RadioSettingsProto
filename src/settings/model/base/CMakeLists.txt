cmake_minimum_required(VERSION 4.1)

project(settings-model-base)

set(CLASSES_BASE_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/AfSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/AgcSpeed.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/AutoCompleteTrigger.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/Band.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/BandRfSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/BandSettingsCacheT.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/IActiveBandSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/IBandSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/IfSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/IRadioSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/IRadioSettingsEvent.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/Mode.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/PipelineId.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/RadioCommands.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/RadioPayloadBase.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/RadioSettingsEventT.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/RadioSettingsShortcutExpander.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/RadioSettingsShortcuts.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/RadioSettingsSink.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/RadioSettingsSinkT.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/RadioSettingsSource.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/RadioSettingsSourceT.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/ReceiverSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/ResolveDottedStringFunc.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/SettingDescriptor.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/SettingPath.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/SettingsBase.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/SettingsEventBaseT.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/SettingUpdate.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/SettingUpdateEventT.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/SettingUpdateSink.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/SettingUpdateSource.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/SettingUpdateVariant.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/SplitBandId.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/StringRef.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/TransmitterSettings.h

        ${CMAKE_CURRENT_LIST_DIR}/src/SettingDescriptor.cpp
)

add_library(settings-model-base STATIC ${CLASSES_BASE_FILES})

target_include_directories(settings-model-base PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-base PUBLIC
        config-struct
        settings-model-proto
        etl::etl
)
