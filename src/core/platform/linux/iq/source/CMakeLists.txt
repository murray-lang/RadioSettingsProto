cmake_minimum_required(VERSION 4.1)

project(core-linux-iq-source)

set(LINUX_IQ_SOURCE_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/iq/source/AudioIqSource.h
        ${CMAKE_CURRENT_LIST_DIR}/include/iq/source/AudioSignalIqSource.h
        ${CMAKE_CURRENT_LIST_DIR}/include/iq/source/IqSourceFactory.h
        ${CMAKE_CURRENT_LIST_DIR}/include/iq/source/IqSourceVariant.h

        ${CMAKE_CURRENT_LIST_DIR}/src/AudioIqSource.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/AudioSignalIqSource.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/IqSourceFactory.cpp
)

add_library(core-linux-iq-source STATIC ${LINUX_IQ_SOURCE_FILES})

target_include_directories(core-linux-iq-source PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(core-linux-iq-source PUBLIC
        core-common-dsp-transforms-hilbert
        core-common-samples
        core-common-audio-base
        core-linux-audio
        core-common-iq-base
        config-struct
)