cmake_minimum_required(VERSION 3.16.3)
project(Cache VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDART 20)

include(cmake/ClangFormat.cmake)

add_subdirectory(run_caches)
add_subdirectory(tests)

if (BENCHMARK)
    add_subdirectory(Cache/benchmark)
endif()