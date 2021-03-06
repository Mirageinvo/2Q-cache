#ifndef CACHE_INCLUDES_CACHE_2Q_IMPL
#define CACHE_INCLUDES_CACHE_2Q_IMPL

#include <cassert>

#include "cache_2q.hpp"

template <typename T, typename KeyT>
cache_2q<T, KeyT>::cache_2q(size_t cache_size)
    : cache_size_(cache_size),
      A_out_size_(cache_size -
                  (static_cast<size_t>(
                      (cache_size - static_cast<size_t>(cache_size / 2)) / 2)) *
                      2),
      A_in_size_(static_cast<size_t>(
          (cache_size - static_cast<size_t>(cache_size / 2)) / 2)),
      A_m_size_(static_cast<size_t>(
          (cache_size - static_cast<size_t>(cache_size / 2)) / 2)) {
  assert(cache_size >= 3);
}

template <typename T, typename KeyT>
void cache_2q<T, KeyT>::remove_from_A_out(T el) {
  auto it = A_out_hash_[el];
  A_out_.erase(it);
  A_out_hash_.erase(el);
}

template <typename T, typename KeyT>
void cache_2q<T, KeyT>::add_to_A_m(T el) {
  assert(A_m_.size() <= A_m_size_);
  if (A_m_.size() == A_m_size_) {
    auto it = A_m_.end();
    it--;
    A_m_hash_.erase(*it);
    A_m_.pop_back();
    A_m_.push_front(el);
    A_m_hash_[el] = A_m_.begin();
  } else {
    A_m_.push_front(el);
    A_m_hash_[el] = A_m_.begin();
  }
}

template <typename T, typename KeyT>
void cache_2q<T, KeyT>::add_to_A_out(T el) {
  assert(A_out_.size() <= A_out_size_);
  if (A_out_.size() == A_out_size_) {
    auto it = A_out_.end();
    it--;
    A_out_hash_.erase(*it);
    A_out_.pop_back();
    A_out_.push_front(el);
    A_out_hash_[el] = A_out_.begin();
  } else {
    A_out_.push_front(el);
    A_out_hash_[el] = A_out_.begin();
  }
}

template <typename T, typename KeyT>
void cache_2q<T, KeyT>::push(T el) {
  assert(A_in_.size() <= A_in_size_);
  if (A_in_.size() == A_in_size_) {
    auto it = A_in_.end();
    it--;
    add_to_A_out(*it);
    A_in_hash_.erase(*it);
    A_in_.pop_back();
    A_in_.push_front(el);
    A_in_hash_[el] = A_in_.begin();
  } else {
    A_in_.push_front(el);
    A_in_hash_[el] = A_in_.begin();
  }
}

template <typename T, typename KeyT>
bool cache_2q<T, KeyT>::query(KeyT key) {
  if (A_m_hash_.find(key) != A_m_hash_.end()) {
    T head_el = *A_m_.begin();
    std::swap(*A_m_.begin(), *A_m_hash_[key]);
    A_m_hash_[head_el] = A_m_hash_[key];
    A_m_hash_[key] = A_m_.begin();
    return true;
  } else if (A_in_hash_.find(key) != A_in_hash_.end()) {
    return true;
  } else if (A_out_hash_.find(key) != A_out_hash_.end()) {
    remove_from_A_out(key);
    add_to_A_m(key);
    return true;
  } else {
    return false;
  }
}

#endif  // CACHE_INCLUDES_CACHE_2Q_IMPL