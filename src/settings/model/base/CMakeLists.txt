cmake_minimum_required(VERSION 4.1)

project(settings-model-base)

set(CLASSES_BASE_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/base/AutoCompleteTrigger.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/base/SettingDescriptor.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/base/SettingPath.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/base/SettingsBase.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/base/SettingUpdate.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/base/SettingUpdateSink.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/base/SettingUpdateSource.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/base/SettingUpdateVariant.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/base/StringRef.h

        ${CMAKE_CURRENT_LIST_DIR}/src/SettingDescriptor.cpp

)

add_library(settings-model-base STATIC ${CLASSES_BASE_FILES})

target_include_directories(settings-model-base PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-base PUBLIC
        config-struct
        etl::etl
)
