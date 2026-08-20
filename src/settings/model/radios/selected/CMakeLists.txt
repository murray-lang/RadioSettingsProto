cmake_minimum_required(VERSION 4.1)

project(settings-model-radios-selected)

set(RADIO_SETTINGS_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/selected/ActiveBandSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/selected/BandSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/selected/BandSettingsCache.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/selected/RadioSettings.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/selected/UpdateHelpers.h
)

set(RADIO_SETTINGS_LIBS
        settings-model-radios-iq-dual-split
        settings-model-path-radios-dual-iq-split-helpers
)

if (USE_DOTTED_STRING_PATHS)
    set(RADIO_SETTINGS_FILES
            ${RADIO_SETTINGS_FILES}
            ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/radios/selected/resolveDottedString.h
    )
    set(RADIO_SETTINGS_LIBS
            ${RADIO_SETTINGS_LIBS}
            settings-model-path-radios-dual-iq-split-lookup
            settings-model-path-util-resolve-one
    )
endif()

add_library(settings-model-radios-selected INTERFACE ${RADIO_SETTINGS_FILES})

target_include_directories(settings-model-radios-selected INTERFACE
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-radios-selected INTERFACE ${RADIO_SETTINGS_LIBS})