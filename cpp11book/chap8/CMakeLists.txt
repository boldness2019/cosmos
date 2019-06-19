cmake_minimum_required(VERSION 3.6)

set_source_files_properties(
    test_single.cpp
    Singleton.hpp
    PROPERTIES COMPILE_FLAGS -std=c++11
)

add_executable(test_single test_single.cpp Singleton.hpp )
