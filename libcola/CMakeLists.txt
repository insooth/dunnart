
cmake_minimum_required(VERSION 3.1.0)

# No MOC, UIC and Qt in libcola.

file(GLOB cola_SOURCES RELATIVE ${CMAKE_CURRENT_LIST_DIR} "*.cpp")

add_library(cola SHARED ${cola_SOURCES})

target_include_directories(cola PUBLIC ${CMAKE_CURRENT_LIST_DIR}/..)
target_link_libraries(cola vpsc)

