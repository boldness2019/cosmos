cmake_minimum_required(VERSION 3.6)

set_source_files_properties(
    main.cpp
    test_bus.cpp
    test_callback.cpp
    MessageBus.hpp
	NonCopyable.hpp
	function_traits.hpp
	Any.hpp
)

add_executable(bus main.cpp MessageBus.hpp NonCopyable.hpp Any.hpp function_traits.hpp)

add_executable(test_bus test_bus.cpp MessageBus.hpp NonCopyable.hpp Any.hpp function_traits.hpp)

add_executable(test_callback test_callback.cpp MessageBus.hpp NonCopyable.hpp Any.hpp function_traits.hpp)

