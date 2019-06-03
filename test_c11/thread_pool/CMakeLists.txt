cmake_minimum_required(VERSION 3.6)

set_source_files_properties(
    main.cpp
    SyncQueue.hpp
    ThreadPool.hpp
    PROPERTIES COMPILE_FLAGS -std=c++11
)

add_executable(thread_pool main.cpp ThreadPool.hpp SyncQueue.hpp)

