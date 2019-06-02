cmake_minimum_required(VERSION 3.6)

set_source_files_properties(
    main.cpp
    sync_deque.hpp
    worker.hpp
    thread_pool.hpp
    PROPERTIES COMPILE_FLAGS -std=c++11
)

add_executable(thread_toop main.cpp sync_deque.hpp worker.hpp thread_pool.hpp)
