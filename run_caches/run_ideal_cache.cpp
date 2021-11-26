#include <cassert>
#include <iostream>

#include "ideal_cache.hpp"
#include "ideal_cache_impl.hpp"

int main() {
  size_t cache_capacity, request_num;
  std::cin >> cache_capacity >> request_num;
  if (cache_capacity < 1) {
    std::cout << std::endl
              << "Inappropriate cache capacity" << std::endl
              << "Cache capacity is less than 1" << std::endl
              << std::endl;
  } else {
    ideal_cache<int> cache(cache_capacity, request_num);
    cache.get_request_arr();
    cache.start_work();

    std::cout << cache.number_of_hits() << std::endl;
  }
  return 0;
}