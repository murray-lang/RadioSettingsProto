cmake_minimum_required(VERSION 4.1)

project(core-common-thread)

add_library(core-common-thread INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include/thread/Runnable.h)
target_include_directories(core-common-thread INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)