#ifndef CACHE_INCLUDES_IDEAL_CACHE
#define CACHE_INCLUDES_IDEAL_CACHE

#include <unordered_map>
#include <vector>
#include <list>

template <typename T>
class ideal_cache {
  public:
    
  private:
    size_t arr_size;
    T* arr;
    std::list<T> cache_list;
    std::unordered_map<int, vector<int>> cache_hash;
}



#endif //CACHE_INCLUDES_IDEAL_CACHE