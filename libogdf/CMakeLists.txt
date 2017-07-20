
cmake_minimum_required(VERSION 3.1.0)

# No MOC, UIC and Qt in libogdf.

file(GLOB_RECURSE ogdf_SOURCES RELATIVE ${CMAKE_CURRENT_LIST_DIR} "src/*.cpp")
add_library(ogdf SHARED ${ogdf_SOURCES})
target_include_directories(ogdf PUBLIC ${CMAKE_CURRENT_LIST_DIR})

