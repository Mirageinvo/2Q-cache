#ifndef CACHE_INCLUDES_IDEAL_CACHE
#define CACHE_INCLUDES_IDEAL_CACHE

#include <fstream>
#include <list>
#include <unordered_map>
#include <vector>

template <typename T>
class ideal_cache final {
 public:
  ideal_cache(size_t cache_capacity, size_t request_arr_size);
  ~ideal_cache();
  void get_request_arr();
  void get_request_arr(std::ifstream& in);
  void start_work();
  int number_of_hits() const;

 private:
  void put_el_in_cache(size_t pos);
  void put_maxdist_el_in_tail(size_t pos);
  int get_dist(T el, size_t pos);

  size_t request_arr_size_;
  size_t cache_capacity_;
  int hit_number_;
  T* request_arr_;
  std::list<T> cache_list_;
  std::unordered_map<T, typename std::list<T>::iterator> list_hash_;
  std::unordered_map<T, std::pair<size_t, std::vector<int>>> order_hash_;
};

#endif  // CACHE_INCLUDES_IDEAL_CACHE