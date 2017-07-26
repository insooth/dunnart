
cmake_minimum_required(VERSION 3.4.3)

# No MOC, UIC and Qt in libtopology.

file(GLOB topology_SOURCES RELATIVE ${CMAKE_CURRENT_LIST_DIR} "*.cpp")

add_library(topology SHARED ${topology_SOURCES})

target_include_directories(topology PUBLIC ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_CURRENT_LIST_DIR}/..)
target_link_libraries(topology vpsc cola avoid)

set_property(TARGET topology PROPERTY WINDOWS_EXPORT_ALL_SYMBOLS ON)
set_property(TARGET topology PROPERTY POSITION_INDEPENDENT_CODE ON)
set_property(TARGET topology PROPERTY CXX_STANDARD 14)

if(MSVC)
  # warnings as errors
  target_compile_options(topology PRIVATE "/WX")

  target_compile_definitions(topology PRIVATE "_CRT_SECURE_NO_WARNINGS=1")
else()
#  target_compile_definitions(topology PRIVATE "-Werror")
endif()

