#include <cassert>
#include <iostream>
#include <unordered_map>

#include "cache_2q.hpp"
#include "cache_2q_impl.hpp"

int slow_get_page(int el, std::unordered_map<int, int>& table) {
  if (table.find(el) == table.end()) {
    table[el] = el;
    return el;
  }
  return table[el];
}

int main() {
  std::unordered_map<int, int> table;
  size_t cache_capacity, request_num;
  int page, num, num_of_hits = 0;
  bool res;
  std::cin >> cache_capacity >> request_num;
  if (cache_capacity < 3) {
    std::cout << std::endl
              << "Inappropriate cache capacity" << std::endl
              << "Cache capacity is less than 3" << std::endl
              << std::endl;
  } else {
    assert(cache_capacity >= 3);

    cache_2q<int> cache(cache_capacity);
    for (size_t i = 0; i < request_num; ++i) {
      std::cin >> num;
      res = cache.query(num);
      num_of_hits += res;
      if (!res) {
        page = slow_get_page(num, table);
        cache.push(num);
      }
    }

    std::cout << num_of_hits << std::endl;
  }
  return 0;
}