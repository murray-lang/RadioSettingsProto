cmake_minimum_required(VERSION 4.1)

project(core-stm32h745i-audio)

set(STM32_AUDIO_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/audio/AdcDacConfig.h
        ${CMAKE_CURRENT_LIST_DIR}/include/audio/AudioInputDriver.h
        ${CMAKE_CURRENT_LIST_DIR}/include/audio/AudioOutputDriver.h

        ${CMAKE_CURRENT_LIST_DIR}/src/AudioInputDriverStm32.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/AudioOutputDriverStm32.cpp
)

add_library(core-stm32h745i-audio STATIC ${STM32_AUDIO_FILES})

target_compile_definitions(core-stm32h745i-audio PUBLIC ADC_BUFFER_SIZE=512)

target_include_directories(core-stm32h745i-audio PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

if (TARGET_PLATFORM STREQUAL "stm32h745i-cm4")
    target_link_libraries(core-stm32h745i-audio PUBLIC
            core-audio-base
            core-stm32h745i-drivers-bsp-disco-cm4
    )

elseif(TARGET_PLATFORM STREQUAL "stm32h745i-cm7")
    target_link_libraries(core-stm32h745i-audio PUBLIC
            core-audio-base
            core-stm32h745i-drivers-bsp-disco-cm7
    )
endif()