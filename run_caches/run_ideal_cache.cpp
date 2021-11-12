#include <iostream>
#include "../Cache/includes/ideal_cache.hpp"
#include "../Cache/includes/ideal_cache_impl.hpp"

int main() {
    int cache_size, request_num;
    int* request_arr;
    ideal_cache<int> cache;
    std::cin >> cache_size >> request_num;

    request_arr = (int*)calloc(request_num, sizeof(int));
    for (int i = 0; i < request_num; ++i) {
        std::cin >> request_arr[i];
    }

    return 0;
}