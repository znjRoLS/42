cmake_minimum_required(VERSION 3.5)
project(42)

# error on warning
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Werror")

# Setup dirs
set(CMAKE_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/cmake-lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/cmake-lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/cmake-bin)

set(BIN_PREFIX cmake-bin/)

# include all
include_directories(./)

add_subdirectory(base)

# always link base library
macro (add_executable _name)
    # invoke built-in add_executable
    _add_executable(${ARGV})
    if (TARGET ${_name})
        target_link_libraries(${_name} base)
    endif()
endmacro()

add_subdirectory(strings)
add_subdirectory(main)
add_subdirectory(googletest)