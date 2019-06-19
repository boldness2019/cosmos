cmake_minimum_required(VERSION 3.6)

set_source_files_properties(
    main.cpp
    main1.cpp
    main2.cpp
	test_ioc.cpp
	TestIoc.cpp
    Ioc.hpp
    Ioc1.hpp
	NonCopyable.hpp
	Any.hpp
	IocContainer.hpp
	IocContainer1.hpp
	IocContainer2.hpp
    PROPERTIES COMPILE_FLAGS -std=c++11
)

add_executable(ioc main.cpp Ioc.hpp NonCopyable.hpp Any.hpp)
add_executable(test_ioc test_ioc.cpp Ioc.hpp NonCopyable.hpp Any.hpp)
add_executable(TestIoc TestIoc.cpp Ioc1.hpp NonCopyable.hpp Any.hpp)

add_executable(ioc1 main1.cpp IocContainer1.hpp NonCopyable.hpp )

add_executable(ioc2 main2.cpp IocContainer2.hpp NonCopyable.hpp Any.hpp )

add_executable(IocContainer main.cpp IocContainer.hpp NonCopyable.hpp Any.hpp)
