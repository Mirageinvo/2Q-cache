#include <benchmark/benchmark.h>

#include <fstream>
#include <iostream>
#include <string>

#include "ideal_cache.hpp"
#include "ideal_cache_impl.hpp"

const int startTest = 3;
const int finalTest = 10;
const int step = 1;

static void BM_Ideal_Cache(benchmark::State& state) {
  size_t cache_capacity, request_num;
  for (auto _ : state) {
    std::string pth = "../../../tests/files_for_tests/0";
    if (state.range() < 10) {
      pth += "0";
    }
    pth += std::to_string(state.range());
    pth += ".dat";
    std::ifstream in;
    in.open(pth);
    in >> cache_capacity >> request_num;
    ideal_cache<int> cache(cache_capacity, request_num);
    cache.get_request_arr(in);
    in.close();
    cache.start_work();
  }
}

BENCHMARK(BM_Ideal_Cache)
    ->DenseRange(startTest, finalTest, step)
    ->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();