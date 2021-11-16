#include <benchmark/benchmark.h>

#include <iostream>
#include <string>

#include "cache_2q.hpp"
#include "cache_2q_impl.hpp"

const int startTest = 3;
const int finalTest = 10;
const int step = 1;

static void BM_Cache_2Q(benchmark::State& state) {
  int num;
  size_t cache_capacity, request_num;
  for (auto _ : state) {
    std::string pth = "../../../tests/files_for_tests/0";
    if (state.range() < 10) {
      pth += "0";
    }
    pth += std::to_string(state.range());
    pth += ".dat";
    FILE* f;
    f = fopen(pth.c_str(), "r");
    fscanf(f, "%lu%lu", &cache_capacity, &request_num);
    cache_2q<int> cache(cache_capacity);
    for (size_t i = 0; i < request_num; ++i) {
      fscanf(f, "%d", &num);
      cache.put(num);
    }
    fclose(f);
  }
}

BENCHMARK(BM_Cache_2Q)
    ->DenseRange(startTest, finalTest, step)
    ->Unit(benchmark::kMillisecond);

BENCHMARK_MAIN();