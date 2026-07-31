cmake_minimum_required(VERSION 4.1)

project(core-stm32h745i-math)

set(STM32_MATH_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/stm32h745i/math/arm_common_tables.h
        ${CMAKE_CURRENT_LIST_DIR}/include/stm32h745i/math/arm_const_structs.h
        ${CMAKE_CURRENT_LIST_DIR}/include/stm32h745i/math/arm_math.h
)

set(DUMMY_FILE ${CMAKE_CURRENT_LIST_DIR}/src/dummy.c )

# Header-only interface (common to both cores)
add_library(core-stm32h745i-math INTERFACE ${STM32_MATH_FILES})
target_include_directories(core-stm32h745i-math INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/include
)

if(TARGET_PLATFORM STREQUAL "stm32h745i-cm7")
    # CM7 variants - choose based on floating point configuration

    # CM7 without FPU
#    add_library(core-stm32h745i-math-cm7l STATIC ${DUMMY_FILE})
#    target_link_libraries(core-stm32h745i-math-cm7l PUBLIC
#            core-stm32h745i-math
#            ${CMAKE_CURRENT_SOURCE_DIR}/lib/libarm_cortexM7l_math.a
#    )

    # CM7 with single-precision FPU
    add_library(core-stm32h745i-cm7-math STATIC ${DUMMY_FILE})
#    add_library(core-stm32h745i-math-cm7lfsp STATIC ${DUMMY_FILE})
    target_link_libraries(core-stm32h745i-cm7-math PUBLIC
            core-stm32h745i-math
            core-stm32h745i-drivers-cmsis
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/libarm_cortexM7lfsp_math.a
    )

    # CM7 with double-precision FPU
#    add_library(core-stm32h745i-math-cm7lfdp STATIC ${DUMMY_FILE})
#    target_link_libraries(core-stm32h745i-math-cm7lfdp PUBLIC
#            core-stm32h745i-math
#            ${CMAKE_CURRENT_SOURCE_DIR}/lib/libarm_cortexM7lfdp_math.a
#    )
endif()

if(TARGET_PLATFORM STREQUAL "stm32h745i-cm4")
    # CM4 variants

    # CM4 without FPU
#    add_library(core-stm32h745i-math-cm4l STATIC ${DUMMY_FILE})
#    target_link_libraries(core-stm32h745i-math-cm4l PUBLIC
#            core-stm32h745i-math
#            ${CMAKE_CURRENT_SOURCE_DIR}/lib/libarm_cortexM4l_math.a
#    )

    # CM4 with FPU
    add_library(core-stm32h745i-cm4-math STATIC ${DUMMY_FILE})
#    add_library(core-stm32h745i-math-cm4lf STATIC ${DUMMY_FILE})
    target_link_libraries(core-stm32h745i-cm4-math PUBLIC
            core-stm32h745i-math
            core-stm32h745i-drivers-cmsis
            ${CMAKE_CURRENT_SOURCE_DIR}/lib/libarm_cortexM4lf_math.a
    )
endif()
