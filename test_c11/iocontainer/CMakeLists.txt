cmake_minimum_required(VERSION 3.6)

set_source_files_properties(
    main.cpp
    Ioc.hpp
	NonCopyable.hpp
	Any.hpp
    PROPERTIES COMPILE_FLAGS -std=c++11
)

add_executable(ioc main.cpp Ioc.hpp NonCopyable.hpp Any.hpp)

set_source_files_properties(
    test_ioc.cpp
    Ioc.hpp
	NonCopyable.hpp
	Any.hpp
    PROPERTIES COMPILE_FLAGS -std=c++11
)

add_executable(test_ioc test_ioc.cpp Ioc.hpp NonCopyable.hpp Any.hpp)

set_source_files_properties(
    TestIoc.cpp
    Ioc.hpp
	NonCopyable.hpp
	Any.hpp
    PROPERTIES COMPILE_FLAGS -std=c++11
)

add_executable(TestIoc TestIoc.cpp Ioc.hpp NonCopyable.hpp Any.hpp)
