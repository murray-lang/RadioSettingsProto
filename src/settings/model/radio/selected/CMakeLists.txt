cmake_minimum_required(VERSION 4.1)

project(settings-model-radio-selected)

set(RADIO_SETTINGS_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radio/ActiveBandSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radio/BandSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radio/BandSettingsCache.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radio/RadioSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radio/RadioSettingsSink.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radio/RadioSettingsSource.h
)

add_library(settings-model-radio-selected INTERFACE ${RADIO_SETTINGS_FILES})

target_include_directories(settings-model-radio-selected INTERFACE
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-radio-selected INTERFACE
#        settings-model-radio-iq-basic-rx
        settings-model-radio-iq-dual-split
)