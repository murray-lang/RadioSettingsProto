cmake_minimum_required(VERSION 4.1)

project(core-audio-base)

set(AUDIO_BASE_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/include/audio/AudioDriverBase.h
        ${CMAKE_CURRENT_LIST_DIR}/include/audio/AudioInputDriverBase.h
        ${CMAKE_CURRENT_LIST_DIR}/include/audio/AudioOutputDriverBase.h
        ${CMAKE_CURRENT_LIST_DIR}/include/audio/AudioSink.h
        ${CMAKE_CURRENT_LIST_DIR}/include/audio/SampleTypes.h
)

add_library(core-audio-base INTERFACE ${AUDIO_BASE_SOURCES})
target_include_directories(core-audio-base INTERFACE
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)
target_link_libraries(core-audio-base INTERFACE etl::etl)