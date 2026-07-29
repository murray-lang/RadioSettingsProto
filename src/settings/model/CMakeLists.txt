cmake_minimum_required(VERSION 4.1)

project(settings-model)

add_definitions(-DMAX_BANDS=34)

add_subdirectory(proto)
add_subdirectory(base)
add_subdirectory(basic)
add_subdirectory(basic-iq)
add_subdirectory(radios)
#add_subdirectory(core)
#add_subdirectory(extra)
add_subdirectory(lookup)
#add_subdirectory(parts)
add_subdirectory(util)
add_subdirectory(traverse)

