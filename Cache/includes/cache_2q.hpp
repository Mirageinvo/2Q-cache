#ifndef CACHE_INCLUDES_CACHE_2Q
#define CACHE_INCLUDES_CACHE_2Q

#include <unordered_map>
#include <list>

template <typename T>
class cache_2q {
  public:
    cache_2q(size_t cache_size);
    void put(T num);
    int number_of_hits() const;

  private:
    void add_to_A_m(T el);
    void add_to_A_in(T el);
    void add_to_A_out(T el);
    void remove_from_A_out(T el);

    size_t cache_size_;
    size_t A_in_size_;
    size_t A_out_size_;
    size_t A_m_size_;
    int hit_number_;
    std::list<T> A_in_;
    std::list<T> A_out_;
    std::list<T> A_m_;
    std::unordered_map<T, T*> A_in_hash_;
    std::unordered_map<T, T*> A_out_hash_;
    std::unordered_map<T, T*> A_m_hash_;
};




#endif //CACHE_INCLUDES_2Q_CACHE