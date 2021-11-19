cmake_minimum_required(VERSION 3.16.3)
project(Cache_run VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDART 20)

set(IDEAL_CACHE_FILE ideal_cache)
set(2Q_CACHE_FILE cache_2q)
set(RUN_IDEAL_CACHE run_${IDEAL_CACHE_FILE})
set(RUN_2Q_CACHE run_${2Q_CACHE_FILE})
SET(PTH "../Cache/includes/")

add_executable(${IDEAL_CACHE_FILE} run_ideal_cache.cpp)
target_include_directories(${IDEAL_CACHE_FILE} PUBLIC ${PTH})

add_executable(${2Q_CACHE_FILE} run_cache_2q.cpp)
target_include_directories(${2Q_CACHE_FILE} PUBLIC ${PTH})

add_custom_target(
    ${RUN_IDEAL_CACHE}
    COMMENT Running Ideal_Cache
    COMMAND ./${IDEAL_CACHE_FILE}
)
add_dependencies(${RUN_IDEAL_CACHE} ${IDEAL_CACHE_FILE})

add_custom_target(
    ${RUN_2Q_CACHE}
    COMMENT Running 2Q_Cache
    COMMAND ./${2Q_CACHE_FILE}
)
add_dependencies(${RUN_2Q_CACHE} ${2Q_CACHE_FILE})