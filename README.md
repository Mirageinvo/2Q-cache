# 2Q Cache and "Ideal" Cache

In this project have been implemented and compared 2Q Cache and "Ideal" Cache(it has an array of requested pages before start).
The caches have been compared with GoogleBenchmark

### To build the project the following is needed to be done:

```
mkdir build && cd build/

cmake .. && make
\\or with sanitizers:\\
cmake -DADD-SANITIZERS=1 .. && make
\\or if user has GoogleBenchmark installed they can try:\\
cmake -DBENCHMARK=1 .. && make

afterwards:

\\to run GoogleTests for either caches:\\
make run_tests_for_caches

\\to run 2Q Cache:\\
make run_cache_2q

\\to run "Ideal" Cache:\\
make run_ideal_cache

\\to use clang format for all *.cpp and *hpp files:\\
make clang_format

\\to run GoogleBenchmark if installed and -DBENCHMARK=1:\\
make run_caches_benchmark
```