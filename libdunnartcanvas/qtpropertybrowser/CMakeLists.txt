
cmake_minimum_required(VERSION 3.1.0)

find_package(Qt5Widgets REQUIRED)

file(GLOB qtpropertybrowser_SOURCES RELATIVE ${CMAKE_CURRENT_LIST_DIR} "*.cpp")

add_library(qtpropertybrowser SHARED ${qtpropertybrowser_SOURCES} qtpropertybrowser.qrc)

target_include_directories(qtpropertybrowser PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(qtpropertybrowser Qt5::Widgets)

set_property(TARGET qtpropertybrowser APPEND PROPERTY COMPILE_DEFINITIONS QT_DISABLE_DEPRECATED_BEFORE=0)
set_property(TARGET qtpropertybrowser PROPERTY AUTORCC ON)
set_property(TARGET qtpropertybrowser PROPERTY AUTOMOC ON)

