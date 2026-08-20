cmake_minimum_required(VERSION 4.1)

project(settings-model-path-all-resolved-generator)

add_executable(settings-model-path-all-resolved-generator
    main.cpp
)

target_link_libraries(settings-model-path-all-resolved-generator PRIVATE
    settings-model-path-util-resolve-many
    settings-model-path-radios-basic-rx-lookup
    settings-model-path-radios-basic-rxtx-lookup
    settings-model-path-radios-basic-iq-rx-lookup
    settings-model-path-radios-basic-iq-rxtx-lookup
    settings-model-path-radios-dual-iq-rx-lookup
    settings-model-path-radios-dual-iq-rxtx-lookup
    settings-model-path-radios-dual-iq-split-lookup
)

target_include_directories(settings-model-path-all-resolved-generator PRIVATE
    ${INCLUDE_DIR}
)

# Pass the source directory to the executable via compile definition
target_compile_definitions(settings-model-path-all-resolved-generator PRIVATE
    SOURCE_PATH="${CMAKE_SOURCE_DIR}/src/settings/model/path"
)
