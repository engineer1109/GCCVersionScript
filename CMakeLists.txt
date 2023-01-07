cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(SymbolVersionExport)

add_library(ClassA SHARED ClassA.cpp ClassA.h ClassA.map)

set_target_properties (ClassA PROPERTIES LINK_FLAGS "-Wl,--version-script -Wl,${CMAKE_CURRENT_SOURCE_DIR}/ClassA.map")