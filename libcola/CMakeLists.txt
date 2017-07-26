
cmake_minimum_required(VERSION 3.4.3)

# No MOC, UIC and Qt in libcola.

file(GLOB cola_SOURCES RELATIVE ${CMAKE_CURRENT_LIST_DIR} "*.cpp")

add_library(cola SHARED ${cola_SOURCES})

target_include_directories(cola PUBLIC ${CMAKE_CURRENT_LIST_DIR}/..)
target_link_libraries(cola vpsc)

set_property(TARGET cola PROPERTY WINDOWS_EXPORT_ALL_SYMBOLS ON)
set_property(TARGET cola PROPERTY POSITION_INDEPENDENT_CODE ON)
set_property(TARGET cola PROPERTY CXX_STANDARD 14)

if(MSVC)
  # warnings as errors
  target_compile_options(cola PRIVATE "/WX")

  target_compile_definitions(cola PRIVATE "_CRT_SECURE_NO_WARNINGS=1")
endif()

