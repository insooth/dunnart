
cmake_minimum_required(VERSION 3.1.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Svg REQUIRED)
find_package(Qt5Xml REQUIRED)
find_package(Qt5Widgets REQUIRED)
#find_package(PkgConfig REQUIRED)
find_package(Threads REQUIRED)
# TODO: the rest + linking against libgvc if found


set(dunnartcanvas_githash_file githash.h)
execute_process(OUTPUT_FILE ${dunnartcanvas_githash_file}
                WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
                COMMAND git show --abbrev-commit
                COMMAND grep "^commit"
                COMMAND cut -f2 -d' '
                COMMAND xargs printf "#define GITHASH \"%s\"")


add_subdirectory(qtpropertybrowser)



file(GLOB dunnartcanvas_SOURCES RELATIVE ${CMAKE_CURRENT_LIST_DIR} "*.cpp")
file(GLOB dunnartcanvas_UI_SOURCES RELATIVE ${CMAKE_CURRENT_LIST_DIR} "ui/*.cpp")

add_library(dunnartcanvas SHARED ${dunnartcanvas_githash_file}
                                 ${dunnartcanvas_SOURCES} ${dunnartcanvas_UI_SOURCES}
                                 libdunnartcanvas.qrc)

set_target_properties(dunnartcanvas PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(dunnartcanvas PUBLIC ${CMAKE_CURRENT_LIST_DIR}
                                                ${CMAKE_CURRENT_LIST_DIR}/..
                                                ${CMAKE_CURRENT_LIST_DIR}/ui
                                                ${CMAKE_CURRENT_LIST_DIR}/../libogdf)

target_link_libraries(dunnartcanvas avoid vpsc topology cola ogdf
                                    qtpropertybrowser
                                    Qt5::Core Qt5::Xml Qt5::Svg Qt5::Widgets)

set_property(TARGET dunnartcanvas PROPERTY AUTOMOC ON)
set_property(TARGET dunnartcanvas PROPERTY AUTORCC ON)
set_property(TARGET dunnartcanvas PROPERTY AUTOUIC ON)

# set output dirs?
set(dunnartcanvas_AUTOUIC_OPTS)
set_property(TARGET dunnartcanvas APPEND PROPERTY INTERFACE_AUTOUIC_OPTIONS ${dunnartcanvas_AUTOUIC_OPTS})


