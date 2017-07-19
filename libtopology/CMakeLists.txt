
cmake_minimum_required(VERSION 3.1.0)

# No MOC, UIC and Qt in libtopology.

file(GLOB topology_SOURCES RELATIVE ${CMAKE_CURRENT_LIST_DIR} "*.cpp")

add_library(topology SHARED ${topology_SOURCES})

target_include_directories(topology PUBLIC ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_CURRENT_LIST_DIR}/..)
target_link_libraries(topology vpsc cola avoid)

