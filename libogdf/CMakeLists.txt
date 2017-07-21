
cmake_minimum_required(VERSION 3.4.3)

# No MOC, UIC and Qt in libogdf.

file(GLOB_RECURSE ogdf_SOURCES RELATIVE ${CMAKE_CURRENT_LIST_DIR} "src/*.cpp")
add_library(ogdf SHARED ${ogdf_SOURCES})
target_include_directories(ogdf PUBLIC ${CMAKE_CURRENT_LIST_DIR})

if(MSVC)
  target_compile_definitions(ogdf PUBLIC OGDF_DLL=1)
  target_compile_definitions(ogdf PUBLIC OGDF_INSTALL=1)

  find_library(PSAPI Psapi)

  if(PSAPI)
    target_link_libraries(ogdf ${PSAPI})
  else()
    message(WARNING "PSAPI library not found. Will use explicit psapi.lib")
    target_link_libraries(ogdf "psapi.lib")
  endif()
endif()

set_property(TARGET ogdf PROPERTY WINDOWS_EXPORT_ALL_SYMBOLS ON)

