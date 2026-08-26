cmake_minimum_required(VERSION 4.1)

project(settings-model-path-radios-dual-iq-rx-lookup)

set(DUAL_IQ_RX_TAG_LOOKUP_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/path/DualIqRxTagLookup.h
        ${CMAKE_CURRENT_LIST_DIR}/src/DualIqRxTagLookup.cpp
)

add_library(settings-model-path-radios-dual-iq-rx-lookup STATIC ${DUAL_IQ_RX_TAG_LOOKUP_FILES})

target_include_directories(settings-model-path-radios-dual-iq-rx-lookup PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-path-radios-dual-iq-rx-lookup PUBLIC
        settings-model-path-common
)