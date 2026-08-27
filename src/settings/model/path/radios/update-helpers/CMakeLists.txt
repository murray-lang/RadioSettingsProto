cmake_minimum_required(VERSION 4.1)

project(settings-model-path-radios-update-helpers)

add_library(settings-model-path-radios-update-helpers INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/update/UpdateHelperVariant.h
)

target_include_directories(settings-model-path-radios-update-helpers INTERFACE
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-path-radios-update-helpers INTERFACE
        settings-model-path-radios-dual-iq-split-helper
)