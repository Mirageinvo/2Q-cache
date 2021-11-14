#include <iostream>
#include <assert.h>
#include "../Cache/includes/ideal_cache.hpp"
#include "../Cache/includes/ideal_cache_impl.hpp"

int main() {
    size_t cache_capacity, request_num;
    std::cin >> cache_capacity >> request_num;
    assert(cache_capacity > 0);

    ideal_cache<int> cache(cache_capacity, request_num);
    cache.get_request_arr();
    cache.start_work();    //the cache starts its work
    return 0;
}