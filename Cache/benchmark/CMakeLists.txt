cmake_minimum_required(VERSION 3.16.3)
project(Caches_benchmark VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDART 20)

find_package(benchmark REQUIRED)

set(IDEAL_CACHE_EXC ideal_cache_benchmark)
set(CACHE_2Q_EXC cache_2q_benchmark)
set(INCL_PATH "../includes")

add_executable(${IDEAL_CACHE_EXC} ideal_cache_benchmark.cpp)
target_link_libraries(${IDEAL_CACHE_EXC} benchmark::benchmark)
target_include_directories(${IDEAL_CACHE_EXC} PUBLIC ${INCL_PATH})

add_executable(${CACHE_2Q_EXC} cache_2q_benchmark.cpp)
target_link_libraries(${CACHE_2Q_EXC} benchmark::benchmark)
target_include_directories(${CACHE_2Q_EXC} PUBLIC ${INCL_PATH})

add_custom_target(
    "run_caches_benchmark"
    COMMENT Running GoogleBenchmark
    COMMAND ./${IDEAL_CACHE_EXC} && ./${CACHE_2Q_EXC}
)
add_dependencies("run_caches_benchmark" ${IDEAL_CACHE_EXC} ${CACHE_2Q_EXC})