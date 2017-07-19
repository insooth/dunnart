
cmake_minimum_required(VERSION 3.1.0)

# No MOC, UIC and Qt in libavoid.

file(GLOB avoid_SOURCES RELATIVE ${CMAKE_CURRENT_LIST_DIR} "*.cpp")

add_library(avoid SHARED ${avoid_SOURCES})

target_include_directories(avoid PUBLIC ${CMAKE_CURRENT_LIST_DIR}/..)

