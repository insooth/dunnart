
cmake_minimum_required(VERSION 3.1.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(PkgConfig REQUIRED)
find_package(Threads REQUIRED)
# TODO: the rest + linking against libgvc if found


set(dunnartcanvas_githash_file githash.h)
if(MSVC)
  add_custom_command(OUTPUT ${dunnartcanvas_githash_file}
                     COMMAND write_gitver.bat ${dunnartcanvas_githash_file})
else
  add_custom_command(OUTPUT ${dunnartcanvas_githash_file}
                     COMMAND git show --abbrev-commit | grep "^commit" | \
                             cut -f2 -d\' \'`; echo \"`cat .hash`define GITHASH \\\"\$\$ver\\\"\" \
                             > ${dunnartcanvas_githash_file};
endif



add_subdirectory(qtpropertybrowser)



file(GLOB dunnartcanvas_SOURCES RELATIVE ${CMAKE_CURRENT_LIST_DIR} "*.cpp")
file(GLOB dunnartcanvas_UI_SOURCES RELATIVE ${CMAKE_CURRENT_LIST_DIR}/ui "*.cpp")

add_library(dunnartcanvas SHARED ${dunnartcanvas_githash_file}
                                 ${dunnartcanvas_SOURCES} ${dunnartcanvas_UI_SOURCES}
                                 libdunnartcanvas.qrc)

target_include_directories(dunnartcanvas PUBLIC ${CMAKE_CURRENT_LIST_DIR}
                                                ${CMAKE_CURRENT_LIST_DIR}/..
                                                ${CMAKE_CURRENT_LIST_DIR}/ui
                                                ${CMAKE_CURRENT_LIST_DIR}/../libogdf)

target_link_libraries(dunnartcanvas avoid vpsc topology cola ogdf
                                    qtpropertybrowser
                                    Qt5::Core Qt5::XML Qt5::SVG Qt5::Widgets)

set_property(TARGET dunnartcanvas PROPERTY AUTOMOC ON)
set_property(TARGET dunnartcanvas PROPERTY AUTORCC ON)
set_property(TARGET dunnartcanvas PROPERTY AUTOUIC ON)

set(dunnartcanvas_AUTOUIC_OPTS) # set output dirs?
set_property(TARGET dunnartcanvas APPEND PROPERTY INTERFACE_AUTOUIC_OPTIONS ${dunnartcanvas_AUTOUIC_OPTS})


