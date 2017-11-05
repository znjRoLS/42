cmake_minimum_required(VERSION 3.5)
project(42)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Werror")

# Setup dirs
set(CMAKE_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/cmake-lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/cmake-lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/cmake-bin)

set(BIN_PREFIX cmake-bin/)

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

#foreach(SRCFOLDER kattis random coj spoj z-trening algorithms)
#    # Compile every .c file to single target
#    file( GLOB APP_SOURCES ${SRCFOLDER}/*.cpp )
#    foreach( sourcefile ${APP_SOURCES} )
#        # I used a simple string replace, to cut off .cpp.
#        get_filename_component( sourcefile_dir ${sourcefile} DIRECTORY)
#        get_filename_component( sourcefile_lastdir ${sourcefile_dir} NAME)
#        get_filename_component( sourcefile_name_cpp ${sourcefile} NAME )
#        string( REPLACE ".cpp" "" sourcefile_name ${sourcefile_name_cpp} )
#        # Make sure YourLib is linked to each app
#        # target_link_libraries( ${testname} YourLib )
#        if (sourcefile_name_cpp MATCHES test_.*)
#            string(LENGTH ${sourcefile_name_cpp} sourcefile_name_length)
#            string(SUBSTRING ${sourcefile_name_cpp} 5 ${sourcefile_name_length}-5 original_sourcefile_name)
#            add_executable( ${sourcefile_lastdir}-${sourcefile_name} ${sourcefile} ${sourcefile_dir}/${original_sourcefile_name})
#            target_link_libraries(${sourcefile_lastdir}-${sourcefile_name} gtest gtest_main gmock)
#        else()
#            add_executable( ${sourcefile_lastdir}-${sourcefile_name} ${sourcefile} )
#        endif(sourcefile_name_cpp MATCHES test_.*)
#
#    endforeach( sourcefile ${APP_SOURCES} )
#endforeach( SRCFOLDER kattis)