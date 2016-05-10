cmake_minimum_required(VERSION 3.5)
project(AutoCGroup)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Find the GTK module using pkg-config
find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)

# Find the sqlite3 module using pkg-config
pkg_check_modules(SQLITE sqlite3)

link_directories(${GTKMM_LIBRARY_DIRS})

include_directories(${GTKMM_INCLUDE_DIRS} ${SQLITE_INCLUDE_DIRS})

set(SOURCE_FILES main.cpp MainWindow.cpp MainWindow.h AboutDialog.cpp AboutDialog.h SqliteHandler.cpp SqliteHandler.h)
add_executable(AutoCGroup ${SOURCE_FILES})

target_link_libraries(AutoCGroup ${GTKMM_LIBRARIES} ${SQLITE_LIBRARIES})