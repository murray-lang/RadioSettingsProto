cmake_minimum_required(VERSION 4.1)

project(core-freertos-thread)

set(STM32_THREAD_SOURCES
        ${CMAKE_CURRENT_LIST_DIR}/include/thread/WaitCondition.h
        ${CMAKE_CURRENT_LIST_DIR}/include/thread/Mutex.h
        ${CMAKE_CURRENT_LIST_DIR}/include/thread/Queue.h
        ${CMAKE_CURRENT_LIST_DIR}/include/thread/Semaphore.h
        ${CMAKE_CURRENT_LIST_DIR}/include/thread/Thread.h

        ${CMAKE_CURRENT_LIST_DIR}/src/WaitConditionFreeRTOS.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/MutexFreeRTOS.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/SemaphoreFreeRTOS.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/ThreadFreeRTOS.cpp
)

add_library(core-freertos-thread STATIC ${STM32_THREAD_SOURCES})
target_include_directories(core-freertos-thread PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)

if(TARGET_PLATFORM STREQUAL "stm32h745i-cm4")
    target_link_libraries(core-freertos-thread PUBLIC
            core-common-thread
            core-stm32h745i-cm4-freertos
    )
elseif(TARGET_PLATFORM STREQUAL "stm32h745i-cm7")
    target_link_libraries(core-freertos-thread PUBLIC
            core-common-thread
            core-stm32h745i-cm7-freertos
    )
endif()