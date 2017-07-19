
cmake_minimum_required(VERSION 3.1.0)

# No MOC, UIC and Qt in libvpsc.

file(GLOB vpsc_SOURCES RELATIVE ${CMAKE_CURRENT_LIST_DIR} "*.cpp")  # NOTE: includes cbuffer.cpp

add_library(vpsc SHARED ${vpsc_SOURCES})

target_include_directories(vpsc PUBLIC ${CMAKE_CURRENT_LIST_DIR}/..)

