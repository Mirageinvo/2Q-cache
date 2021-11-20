#include <cassert>
#include <iostream>

#include "cache_2q.hpp"
#include "cache_2q_impl.hpp"

int main() {
  size_t cache_capacity, request_num;
  int num, num_of_hits = 0;
  std::cin >> cache_capacity >> request_num;
  assert(cache_capacity >= 3);

  cache_2q<int> cache(cache_capacity);
  for (size_t i = 0; i < request_num; ++i) {
    std::cin >> num;
    num_of_hits += cache.check_in(num);
  }

  std::cout << num_of_hits << std::endl;
  return 0;
}