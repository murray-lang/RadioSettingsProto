cmake_minimum_required(VERSION 4.1)

project(core-stm32h745i-iq-source)

set(STM32_IQ_SOURCE_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/iq/source/AdcIqSource.h
        ${CMAKE_CURRENT_LIST_DIR}/include/iq/source/IqSourceFactory.h
        ${CMAKE_CURRENT_LIST_DIR}/include/iq/source/IqSourceVariant.h

        ${CMAKE_CURRENT_LIST_DIR}/src/AdcIqSource.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/IqSourceFactory.cpp
)



add_library(core-stm32h745i-iq-source STATIC ${STM32_IQ_SOURCE_FILES})

target_compile_definitions(core-stm32h745i-iq-source PUBLIC
        SAMPLE_RATE=192000
        ADC_BUFFER_SIZE=512
        STACK_SIZE=2048
        THREAD_PRIORITY=6
)

target_include_directories(core-stm32h745i-iq-source PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

if(TARGET_PLATFORM STREQUAL "stm32h745i-cm4")
    target_link_libraries(core-stm32h745i-iq-source PUBLIC
            core-common-iq-base
            core-stm32h745i-setup-setup1-cm4
            core-freertos-thread
            etl::etl
    )
elseif(TARGET_PLATFORM STREQUAL "stm32h745i-cm7")
    target_link_libraries(core-stm32h745i-iq-source PUBLIC
            core-common-iq-base
            core-stm32h745i-setup-setup1-cm7
            core-freertos-thread
            etl::etl
    )
endif()