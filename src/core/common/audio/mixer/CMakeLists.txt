cmake_minimum_required(VERSION 4.1)

project(core-common-audio-mixer)

set(AUDIO_MIXER_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/audio/mixer/AudioMixer.h
        ${CMAKE_CURRENT_LIST_DIR}/include/audio/mixer/AudioMixerInput.h

        ${CMAKE_CURRENT_LIST_DIR}/src/AudioMixer.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/AudioMixerInput.cpp
)

add_library(core-common-audio-mixer STATIC ${AUDIO_MIXER_FILES})

target_include_directories(core-common-audio-mixer PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(core-common-audio-mixer PUBLIC
        core-common-audio-base
        core-common-samples
)