cmake_minimum_required(VERSION 3.6)

set_source_files_properties(
    test_single.cpp
    Singleton.hpp
    test_observer.cpp
    Observer.hpp
    Observer.cc
    test_visitor.cpp
    Visitor.hpp
    test_command.cpp
    Command.hpp
    test_object.cpp
    ObjectPool.hpp
    PROPERTIES COMPILE_FLAGS -std=c++11
)

add_executable(test_single test_single.cpp Singleton.hpp )

add_executable(test_observer test_observer.cpp Observer.hpp )

add_executable(test_visitor test_visitor.cpp Visitor.hpp )

add_executable(test_command test_command.cpp Command.hpp )

add_executable(test_object test_object.cpp ObjectPool.hpp )

add_executable(safe_observer Observer.cc )
