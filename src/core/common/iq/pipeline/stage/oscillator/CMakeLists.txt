cmake_minimum_required(VERSION 4.1)

project(core-common-iq-pipeline-stage-oscillator)

set(OSCILLATOR_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/include/iq/oscillator/Oscillator.h
        ${CMAKE_CURRENT_LIST_DIR}/include/iq/oscillator/OscillatorInjector.h
        ${CMAKE_CURRENT_LIST_DIR}/include/iq/oscillator/OscillatorMixer.h
        ${CMAKE_CURRENT_LIST_DIR}/include/iq/oscillator/OscillatorStage.h
        ${CMAKE_CURRENT_LIST_DIR}/include/iq/oscillator/TwoToneSignalStage.h

        ${CMAKE_CURRENT_LIST_DIR}/src/Oscillator.cpp

)

add_library(core-common-iq-pipeline-stage-oscillator STATIC ${OSCILLATOR_SOURCES})
target_include_directories(core-common-iq-pipeline-stage-oscillator PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)
target_link_libraries(core-common-iq-pipeline-stage-oscillator PUBLIC
        core-common-samples
        core-common-dsp-constants
        core-common-iq-pipeline-stage-base
)