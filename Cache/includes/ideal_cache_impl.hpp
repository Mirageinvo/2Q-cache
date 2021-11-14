#ifndef CACHE_INCLUDES_IDEAL_CACHE_IMP
#define CACHE_INCLUDES_IDEAL_CACHE_IMP

#include <iostream>
#include <utility>
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
        if (order_hash.find(request_arr_[i]) == order_hash.end()) {
            order_hash[request_arr_[i]] = { 0, { i } };
        }
        else {
            order_hash[request_arr_[i]].second.push_back(i);
        }
    }
}

/*template <typename T>
size_t ideal_cache<T>::cache_cur_size() const {
    return cur_size_;
}*/

template <typename T>
int ideal_cache<T>::number_of_hits() const {
    return hit_number_;
}

template <typename T>
int ideal_cache<T>::get_dist(T el, size_t pos) {
    int ret;
    assert(order_hash.find(el) != order_hash.end());
    if (order_hash[el].first == order_hash[el].second.size()) {
            ret = -1;
        }
        else {
            ret = order_hash[el].second[order_hash[el].first] - static_cast<int>(pos);
        }
    return ret;
}

template <typename T>
void ideal_cache<T>::put_el_in_cache(size_t pos) {
    T el = request_arr_[pos];
    auto find_res = list_hash.find(el);
    if (find_res == list_hash.end()) {
        if (cur_size_ < cache_capacity_) {
            cache_list.push_back(el);
            auto tmp = cache_list.end();
            tmp--;
            list_hash[el] = tmp;
            cur_size_++;
        }
        else {
            list_hash.erase(*tmp);
            cache_list.pop_back();
            cache_list.push_back(el);
            auto tmp = cache_list.end();
            tmp--;
            list_hash[el] = tmp;
        }
        order_hash[el].first++;
    }
    else {
        hit_number_++;
    }
}

template <typename T>
void ideal_cache<T>::put_maxdist_el_in_tail(size_t pos) {
    auto pretendent_iter = cache_list.begin();
    int val;
    T el;
    for (auto it = cache_list.begin(); it != cache_list.end(); ++it) {
        el = *it;
        val = get_dist(*it, pos);
        if (val == -1) {
            pretendent_iter = it;
            break;
        }
        else if (get_dist(*pretendent_iter, pos) < val) {
            pretendent_iter = it;
        }
    }
    auto tmp = cache_list.end();
    tmp--;
    std::swap(*pretendent_iter, *tmp);
    list_hash[*tmp] = pretendent_iter;
    list_hash[*pretendent_iter] = tmp;
    assert(std::next(list_hash[*pretendent_iter]) == cache_list.end());
}

template <typename T>
void ideal_cache<T>::start_work() {
    for (size_t i = 0; i < request_arr_size_; ++i) {
        put_el_in_cache(i);
        put_maxdist_el_in_tail();
    }
}

#endif //CACHE_INCLUDES_IDEAL_CACHE_IMP