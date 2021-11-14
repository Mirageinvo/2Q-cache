#ifndef CACHE_INCLUDES_IDEAL_CACHE_IMP
#define CACHE_INCLUDES_IDEAL_CACHE_IMP

#include <iostream>
#include "ideal_cache.hpp"

template <typename T>
ideal_cache<T>::ideal_cache(size_t cache_capacity, size_t request_arr_size)
                            : request_arr_(new T[request_arr_size]),
                              request_arr_size_(request_arr_size),
                              cache_capacity_(cache_capacity),
                              cur_size_(0),
                              hit_number_(0) {}

template <typename T>
ideal_cache<T>::~ideal_cache() {
    delete[] request_arr_;
}

template <typename T>
void ideal_cache<T>::get_request_arr() {
    for (size_t i = 0; i < request_arr_size_; ++i) {
        std::cin >> request_arr_[i];
        
    }
}

template <typename T>
size_t ideal_cache<T>::cache_cur_size() const {
    return cur_size_;
}

template <typename T>
int ideal_cache<T>::number_of_hits() const {
    return hit_number_;
}

template <typename T>
void ideal_cache<T>::put_el_in_cache(size_t pos) {
    T el = request_arr_[pos];
    auto tmp = cache_list.end();
    tmp--;
    auto find_res = list_hash.find(el);
    if (find_res == list_hash.end()) {
        list_hash[el] = tmp;
        order_hash[el] = { 0, { pos } };
        if (cur_size_ < cache_capacity_) {
            cache_list.push_back(el);
        }
    }
    else {

    }
}

template <typename T>
void ideal_cache<T>::start_work() {
    for (size_t i = 0; i < request_arr_size_; ++i) {
        put_el_in_cache(i);

    }
}

#endif //CACHE_INCLUDES_IDEAL_CACHE_IMP