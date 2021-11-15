#ifndef CACHE_INCLUDES_CACHE_2Q_IMPL
#define CACHE_INCLUDES_CACHE_2Q_IMPL

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
void cache_2q<T>::put(T el) {
    if ((auto pos = A_m_.find(el)) != A_m_.end()) {
        T head_el = *A_m_.begin();
        std::swap(*A_m_.begin(), *pos);
        A_m_hash_[head_el] = &(*pos);
        A_m_hash_[el] = &(*A_m_.begin());
    }
    else if (A_in_.find(el) != A_in_.end()) {
        hit_number_++;
        continue;
    }
    else if ((auto pos = A_out_.find(el)) != A_out_.end()) {

    }
    else {

    }
}


#endif //CACHE_INCLUDES_CACHE_2Q_IMPL