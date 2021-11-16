#ifndef CACHE_INCLUDES_CACHE_2Q_IMPL
#define CACHE_INCLUDES_CACHE_2Q_IMPL

#include <assert.h>

#include "cache_2q.hpp"

template <typename T>
cache_2q<T>::cache_2q(size_t cache_size) {
  assert(cache_size > 3);
  cache_size_ = cache_size;
  hit_number_ = 0;
  A_in_size_ = A_m_size_ = static_cast<size_t>(cache_size_ / 4);
  A_out_size_ = cache_size_ - (A_in_size_ + A_m_size_);
}

template <typename T>
int cache_2q<T>::number_of_hits() const {
  return hit_number_;
}

template <typename T>
void cache_2q<T>::remove_from_A_out(T el) {
  auto it = A_out_.end();
  for (auto i = A_out_.begin(); i != A_out_.end(); ++i) {
    if (*i == el) {
      it = i;
      break;
    }
  }
  assert(it != A_out_.end());
  A_out_.erase(it);
  A_out_hash_.erase(el);
}

template <typename T>
void cache_2q<T>::add_to_A_m(T el) {
  assert(A_m_.size() <= A_m_size_);
  if (A_m_.size() == A_m_size_) {
    auto it = A_m_.end();
    it--;
    A_m_hash_.erase(*it);
    A_m_.pop_back();
    A_m_.push_front(el);
    A_m_hash_[el] = &(*A_m_.begin());
  } else {
    A_m_.push_front(el);
    A_m_hash_[el] = &(*A_m_.begin());
  }
}

template <typename T>
void cache_2q<T>::add_to_A_out(T el) {
  assert(A_out_.size() <= A_out_size_);
  if (A_out_.size() == A_out_size_) {
    auto it = A_out_.end();
    it--;
    A_out_hash_.erase(*it);
    A_out_.pop_back();
    A_out_.push_front(el);
    A_out_hash_[el] = &(*A_out_.begin());
  } else {
    A_out_.push_front(el);
    A_out_hash_[el] = &(*A_out_.begin());
  }
}

template <typename T>
void cache_2q<T>::add_to_A_in(T el) {
  assert(A_in_.size() <= A_in_size_);
  if (A_in_.size() == A_in_size_) {
    auto it = A_in_.end();
    it--;
    add_to_A_out(*it);
    A_in_hash_.erase(*it);
    A_in_.pop_back();
    A_in_.push_front(el);
    A_in_hash_[el] = &(*A_in_.begin());
  } else {
    A_in_.push_front(el);
    A_in_hash_[el] = &(*A_in_.begin());
  }
}

template <typename T>
void cache_2q<T>::put(T el) {
  if (A_m_hash_.find(el) != A_m_hash_.end()) {
    T head_el = *A_m_.begin();
    std::swap(*A_m_.begin(), *A_m_hash_[el]);
    A_m_hash_[head_el] = A_m_hash_[el];
    A_m_hash_[el] = &(*A_m_.begin());
    hit_number_++;
  } else if (A_in_hash_.find(el) != A_in_hash_.end()) {
    hit_number_++;
  } else if (A_out_hash_.find(el) != A_out_hash_.end()) {
    remove_from_A_out(el);
    add_to_A_m(el);
    hit_number_++;
  } else {
    add_to_A_in(el);
  }
}

#endif  // CACHE_INCLUDES_CACHE_2Q_IMPL