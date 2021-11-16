#include <iostream>
#include <stdio.h>
#include <assert.h>

#include "../Cache/includes/cache_2q.hpp"
#include "../Cache/includes/cache_2q_impl.hpp"

int main() {
  size_t cache_capacity, request_num;
  int num;
  std::cin >> cache_capacity >> request_num;
  assert(cache_capacity > 3);

  cache_2q<int> cache(cache_capacity);
  for (size_t i = 0; i < request_num; ++i) {
    scanf("%d", &num);
    cache.put(num);
  }

  std::cout << cache.number_of_hits() << std::endl;
  return 0;
}