
cmake_minimum_required(VERSION 3.4.3)

# No MOC, UIC and Qt in libavoid.

file(GLOB avoid_SOURCES RELATIVE ${CMAKE_CURRENT_LIST_DIR} "*.cpp")

add_library(avoid SHARED ${avoid_SOURCES})

target_include_directories(avoid PUBLIC ${CMAKE_CURRENT_LIST_DIR}/..)

target_compile_definitions(avoid PUBLIC LIBAVOID_EXPORTS=1)

# sometimes AVOID_EXPORT is missing...
set_property(TARGET avoid PROPERTY WINDOWS_EXPORT_ALL_SYMBOLS ON)
set_property(TARGET avoid PROPERTY POSITION_INDEPENDENT_CODE ON)
set_property(TARGET avoid PROPERTY CXX_STANDARD 14)

