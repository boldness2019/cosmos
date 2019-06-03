cmake_minimum_required(VERSION 3.6)

set_source_files_properties(
    main.cpp
    MessageBus.hpp
	NonCopyable.hpp
	function_traits.hpp
	Any.hpp
)

add_executable(bus main.cpp MessageBus.hpp NonCopyable.hpp Any.hpp function_traits.hpp)

set_source_files_properties(
    test_bus.cpp
    MessageBus.hpp
	NonCopyable.hpp
	function_traits.hpp
	Any.hpp
)

add_executable(test_bus test_bus.cpp MessageBus.hpp NonCopyable.hpp Any.hpp function_traits.hpp)


