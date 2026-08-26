
cmake_minimum_required(VERSION 4.1)

project(settings-model-radios-base)

set(MODEL_RADIO_BASE_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/base/IRadioSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/base/SettingUpdateHelper.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/base/RadioPayloadBase.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/base/RadioSettingsBaseT.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/base/RadioSettingsEventT.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/base/RadioSettingsSink.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/base/RadioSettingsSinkT.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/base/RadioSettingsSource.h
)

add_library(settings-model-radios-base INTERFACE ${MODEL_RADIO_BASE_FILES})

target_include_directories(settings-model-radios-base INTERFACE
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-radios-base INTERFACE
        settings-model-traverse
        settings-model-data-radio
        settings-model-radios-common-component
)