cmake_minimum_required(VERSION 3.6)

set_source_files_properties(
    main.cpp
    Aspect.hpp
	NonCopyable.hpp
	Timer.hpp
    PROPERTIES COMPILE_FLAGS -std=c++11
)

add_executable(aspector main.cpp Aspect.hpp NonCopyable.hpp Timer.hpp)

