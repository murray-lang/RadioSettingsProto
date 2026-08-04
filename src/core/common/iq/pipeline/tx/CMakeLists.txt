cmake_minimum_required(VERSION 4.1)

project(core-common-iq-pipeline-tx)

set(PIPELINE_TX_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/iq/pipeline/IqTxPipeline.h
        ${CMAKE_CURRENT_LIST_DIR}/src/IqTxPipeline.cpp
)

add_library(core-common-iq-pipeline-tx STATIC ${PIPELINE_TX_FILES})

target_include_directories(core-common-iq-pipeline-tx PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(core-common-iq-pipeline-tx PUBLIC
        core-common-iq-pipeline-base
        core-common-iq-pipeline-stage-correction
        core-common-iq-pipeline-stage-filter
        core-common-iq-pipeline-stage-modulation
        core-common-iq-pipeline-stage-resample
)