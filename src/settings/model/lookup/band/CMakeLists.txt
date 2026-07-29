cmake_minimum_required(VERSION 4.1)

project(settings-model-lookup-band)

set(BAND_LOOKUP_FILES
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/lookup/band/BandCategoryList.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/lookup/band/BandList.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/lookup/band/mostBandCategories.h
        ${CMAKE_CURRENT_LIST_DIR}/include/settings/model/lookup/band/BandTypes.h

        ${CMAKE_CURRENT_LIST_DIR}/src/BandCategoryList.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/BandList.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/mostBandCategories.cpp
)

add_library(settings-model-lookup-band STATIC ${BAND_LOOKUP_FILES})

target_include_directories(settings-model-lookup-band PUBLIC
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/include
)

target_link_libraries(settings-model-lookup-band PUBLIC
        settings-model-proto
        etl::etl
)