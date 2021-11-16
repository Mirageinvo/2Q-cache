#ifndef CACHE_INCLUDES_IDEAL_CACHE_IMPL
#define CACHE_INCLUDES_IDEAL_CACHE_IMPL

#include <stdio.h>
#include <cassert>
#include "ideal_cache.hpp"

template <typename T>
ideal_cache<T>::ideal_cache(size_t cache_capacity, size_t request_arr_size)
    : request_arr_(new T[request_arr_size]),
      request_arr_size_(request_arr_size),
      cache_capacity_(cache_capacity),
      hit_number_(0) {}

template <typename T>
ideal_cache<T>::~ideal_cache() {
  delete[] request_arr_;
}

template <typename T>
void ideal_cache<T>::get_request_arr(bool file, FILE* f) {
  if (file) {
    for (size_t i = 0; i < request_arr_size_; ++i) {
      fscanf(f, "%d", &request_arr_[i]);
      if (order_hash_.find(request_arr_[i]) == order_hash_.end()) {
        order_hash_[request_arr_[i]] = {0, {static_cast<int>(i)}};
      } 
      else {
        order_hash_[request_arr_[i]].second.push_back(i);
      }
    }
  }
  else{
    for (size_t i = 0; i < request_arr_size_; ++i) {
      scanf("%d", &request_arr_[i]);
      if (order_hash_.find(request_arr_[i]) == order_hash_.end()) {
        order_hash_[request_arr_[i]] = {0, {static_cast<int>(i)}};
      } 
      else {
        order_hash_[request_arr_[i]].second.push_back(i);
      }
    }
  }
}

template <typename T>
int ideal_cache<T>::number_of_hits() const {
  return hit_number_;
}

template <typename T>
int ideal_cache<T>::get_dist(T el, size_t pos) {
  int ret;
  assert(order_hash_.find(el) != order_hash_.end());
  if (order_hash_[el].first == order_hash_[el].second.size()) {
    ret = -1;
  } else {
    ret = order_hash_[el].second[order_hash_[el].first] - static_cast<int>(pos);
  }
  return ret;
}

template <typename T>
void ideal_cache<T>::put_el_in_cache(size_t pos) {
  T el = request_arr_[pos];
  auto find_res = list_hash_.find(el);
  if (find_res == list_hash_.end()) {
    if (cache_list_.size() < cache_capacity_) {
      cache_list_.push_back(el);
      auto tmp = cache_list_.end();
      tmp--;
      list_hash_[el] = &(*tmp);
    } else {
      auto tmp = cache_list_.end();
      tmp--;
      list_hash_.erase(*tmp);
      cache_list_.pop_back();
      cache_list_.push_back(el);
      tmp = cache_list_.end();
      tmp--;
      list_hash_[el] = &(*tmp);
    }
  } else {
    hit_number_++;
  }
  order_hash_[el].first++;
}

template <typename T>
void ideal_cache<T>::put_maxdist_el_in_tail(size_t pos) {
  auto pretendent_iter = cache_list_.begin();
  int val;
  for (auto it = cache_list_.begin(); it != cache_list_.end(); ++it) {
    val = get_dist(*it, pos);
    if (val == -1) {
      pretendent_iter = it;
      break;
    } else if (get_dist(*pretendent_iter, pos) < val) {
      pretendent_iter = it;
    }
  }
  auto tmp = cache_list_.end();
  tmp--;
  std::swap(*pretendent_iter, *tmp);
  list_hash_[*tmp] = &(*pretendent_iter);
  list_hash_[*pretendent_iter] = &(*tmp);
  tmp = cache_list_.end();
  tmp--;
  assert(*list_hash_[*pretendent_iter] == *tmp);
}

template <typename T>
void ideal_cache<T>::start_work() {
  for (size_t i = 0; i < request_arr_size_; ++i) {
    put_el_in_cache(i);
    put_maxdist_el_in_tail(i);
  }
}

#endif  // CACHE_INCLUDES_IDEAL_CACHE_IMPL