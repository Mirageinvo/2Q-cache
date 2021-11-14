#ifndef CACHE_INCLUDES_IDEAL_CACHE
#define CACHE_INCLUDES_IDEAL_CACHE

#include <unordered_map>
#include <vector>
#include <list>
//#include <utility>

template <typename T>
class ideal_cache {
  public:
    ideal_cache(size_t cache_capacity, size_t request_arr_size);
    ~ideal_cache();

    void get_request_arr();
    int number_of_hits() const;
    void start_work();

    //////////to debug
    void pr_list() const;
    //////

  private:
    void put_el_in_cache(size_t pos);
    void put_maxdist_el_in_tail(size_t pos);
    int get_dist(T el, size_t pos);
    size_t cur_size_;
    size_t request_arr_size_;
    size_t cache_capacity_;
    int hit_number_;
    T* request_arr_;
    std::list<T> cache_list;
    std::unordered_map<T, T*> list_hash;
    std::unordered_map<T, std::pair<size_t, std::vector<int>>> order_hash;
};

#endif //CACHE_INCLUDES_IDEAL_CACHE