#include <iostream>
#include <stdio.h>
#include "../Cache/includes/ideal_cache.hpp"
#include "../Cache/includes/ideal_cache_impl.hpp"
#include "../Cache/includes/cache_2q.hpp"
#include "../Cache/includes/cache_2q_impl.hpp"

int main() {
    size_t cache_capacity, request_num;
    FILE* f;
    f = fopen("tests/files_for_tests/005.dat", "r");
    fscanf(f, "%lu %lu", &cache_capacity, &request_num);
    ideal_cache<int> cache(cache_capacity, request_num);
    cache.get_request_arr(true, f);
    fclose(f);
    cache.start_work();
    std::cout<<cache.number_of_hits()<<std::endl;
    return 0;
}