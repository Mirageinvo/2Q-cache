#ifndef CACHE_INCLUDES_CACHE_2Q
#define CACHE_INCLUDES_CACHE_2Q

#include <list>
#include <unordered_map>

template <typename T, typename KeyT>
class cache_2q final {
 public:
  cache_2q(size_t cache_size);
  bool query(KeyT key);
  void push(T el);

 private:
  void add_to_A_out(T el);
  void add_to_A_m(T el);
  void remove_from_A_out(T el);

  size_t cache_size_;
  size_t A_in_size_;
  size_t A_out_size_;
  size_t A_m_size_;
  std::list<T> A_in_;
  std::list<T> A_out_;
  std::list<T> A_m_;
  std::unordered_map<KeyT, typename std::list<T>::iterator> A_in_hash_;
  std::unordered_map<KeyT, typename std::list<T>::iterator> A_out_hash_;
  std::unordered_map<KeyT, typename std::list<T>::iterator> A_m_hash_;
};

#endif  // CACHE_INCLUDES_2Q_CACHE