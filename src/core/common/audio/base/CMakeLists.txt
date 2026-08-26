cmake_minimum_required(VERSION 4.1)

project(core-common-audio-base)

set(AUDIO_BASE_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/include/audio/AudioBase.h
        ${CMAKE_CURRENT_LIST_DIR}/include/audio/AudioInputBase.h
        ${CMAKE_CURRENT_LIST_DIR}/include/audio/AudioOutputBase.h
        ${CMAKE_CURRENT_LIST_DIR}/include/audio/AudioSink.h
)

add_library(core-common-audio-base INTERFACE ${AUDIO_BASE_SOURCES})
target_include_directories(core-common-audio-base INTERFACE
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)
target_link_libraries(core-common-audio-base INTERFACE
        core-common-samples
        etl::etl
)
