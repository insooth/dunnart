
cmake_minimum_required(VERSION 3.4.3)

# No MOC, UIC and Qt in libvpsc.

file(GLOB vpsc_SOURCES RELATIVE ${CMAKE_CURRENT_LIST_DIR} "*.cpp")  # NOTE: includes cbuffer.cpp

add_library(vpsc SHARED ${vpsc_SOURCES})

target_include_directories(vpsc PUBLIC ${CMAKE_CURRENT_LIST_DIR}/..)

set_property(TARGET vpsc PROPERTY WINDOWS_EXPORT_ALL_SYMBOLS ON)
set_property(TARGET vpsc PROPERTY POSITION_INDEPENDENT_CODE ON)
set_property(TARGET vpsc PROPERTY CXX_STANDARD 14)

