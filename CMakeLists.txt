cmake_minimum_required(VERSION 3.0)

set(SIMPLE_CONTAINER_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src   CACHE PATH "Path to src folder")
set(SIMPLE_CONTAINER_TEST_DIR   ${CMAKE_CURRENT_SOURCE_DIR}/test  CACHE PATH "Path to test folder")

set(SIMPLE_CONTAINER_ARCHIVE_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin CACHE PATH "Path to bin folder")
set(SIMPLE_CONTAINER_LIBRARY_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin CACHE PATH "Path to bin folder")
set(SIMPLE_CONTAINER_RUNTIME_OUTPUT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/bin CACHE PATH "Path to bin folder")

add_subdirectory(src)
add_subdirectory(test)

# Global Solution
project(SimpleContainer)

# Visual Studio project folder
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake Targets")
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
