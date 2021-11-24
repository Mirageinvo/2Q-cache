#include <iostream>

#include "cache_2q.hpp"
#include "cache_2q_impl.hpp"
#include "gtest/gtest.h"
#include "ideal_cache.hpp"
#include "ideal_cache_impl.hpp"

TEST(IdealCache, TestOne) {
  size_t cache_capacity, request_num;
  std::ifstream in;
  in.open("../../tests/files_for_tests/001.dat");
  in >> cache_capacity >> request_num;
  ideal_cache<int> cache(cache_capacity, request_num);
  cache.get_request_arr(in);
  in.close();
  cache.start_work();
  EXPECT_EQ(cache.number_of_hits(), 4);
}

TEST(IdealCache, TestTwo) {
  size_t cache_capacity, request_num;
  std::ifstream in;
  in.open("../../tests/files_for_tests/002.dat");
  in >> cache_capacity >> request_num;
  ideal_cache<int> cache(cache_capacity, request_num);
  cache.get_request_arr(in);
  in.close();
  cache.start_work();
  EXPECT_EQ(cache.number_of_hits(), 0);
}

TEST(IdealCache, TestThree) {
  size_t cache_capacity, request_num;
  std::ifstream in;
  in.open("../../tests/files_for_tests/003.dat");
  in >> cache_capacity >> request_num;
  ideal_cache<int> cache(cache_capacity, request_num);
  cache.get_request_arr(in);
  in.close();
  cache.start_work();
  EXPECT_EQ(cache.number_of_hits(), 6);
}

TEST(IdealCache, TestFour) {
  size_t cache_capacity, request_num;
  std::ifstream in;
  in.open("../../tests/files_for_tests/004.dat");
  in >> cache_capacity >> request_num;
  ideal_cache<int> cache(cache_capacity, request_num);
  cache.get_request_arr(in);
  in.close();
  cache.start_work();
  EXPECT_EQ(cache.number_of_hits(), 17);
}

TEST(IdealCache, TestFive) {
  size_t cache_capacity, request_num;
  std::ifstream in;
  in.open("../../tests/files_for_tests/005.dat");
  in >> cache_capacity >> request_num;
  ideal_cache<int> cache(cache_capacity, request_num);
  cache.get_request_arr(in);
  in.close();
  cache.start_work();
  EXPECT_EQ(cache.number_of_hits(), 63);
}

TEST(IdealCache, TestSix) {
  size_t cache_capacity, request_num;
  std::ifstream in;
  in.open("../../tests/files_for_tests/006.dat");
  in >> cache_capacity >> request_num;
  ideal_cache<int> cache(cache_capacity, request_num);
  cache.get_request_arr(in);
  in.close();
  cache.start_work();
  EXPECT_EQ(cache.number_of_hits(), 327);
}

TEST(IdealCache, TestSeven) {
  size_t cache_capacity, request_num;
  std::ifstream in;
  in.open("../../tests/files_for_tests/007.dat");
  in >> cache_capacity >> request_num;
  ideal_cache<int> cache(cache_capacity, request_num);
  cache.get_request_arr(in);
  in.close();
  cache.start_work();
  EXPECT_EQ(cache.number_of_hits(), 742);
}

TEST(IdealCache, TestEight) {
  size_t cache_capacity, request_num;
  std::ifstream in;
  in.open("../../tests/files_for_tests/008.dat");
  in >> cache_capacity >> request_num;
  ideal_cache<int> cache(cache_capacity, request_num);
  cache.get_request_arr(in);
  in.close();
  cache.start_work();
  EXPECT_EQ(cache.number_of_hits(), 6706);
}

TEST(IdealCache, TestNine) {
  size_t cache_capacity, request_num;
  std::ifstream in;
  in.open("../../tests/files_for_tests/009.dat");
  in >> cache_capacity >> request_num;
  ideal_cache<int> cache(cache_capacity, request_num);
  cache.get_request_arr(in);
  in.close();
  cache.start_work();
  EXPECT_EQ(cache.number_of_hits(), 3846);
}

TEST(Cache2Q, TestOne) {
  bool res;
  size_t cache_capacity, request_num;
  int num, num_of_hits = 0;
  std::ifstream in;
  in.open("../../tests/files_for_tests/002.dat");
  in >> cache_capacity >> request_num;
  cache_2q<int> cache(cache_capacity);
  for (size_t i = 0; i < request_num; ++i) {
    in >> num;
    res = cache.query(num);
    num_of_hits += res;
    if (!res) {
      cache.push(num);
    }
  }
  in.close();
  EXPECT_EQ(num_of_hits, 0);
}

TEST(Cache2Q, TestTwo) {
  bool res;
  size_t cache_capacity, request_num;
  int num, num_of_hits = 0;
  std::ifstream in;
  in.open("../../tests/files_for_tests/003.dat");
  in >> cache_capacity >> request_num;
  cache_2q<int> cache(cache_capacity);
  for (size_t i = 0; i < request_num; ++i) {
    in >> num;
    res = cache.query(num);
    num_of_hits += res;
    if (!res) {
      cache.push(num);
    }
  }
  in.close();
  EXPECT_EQ(num_of_hits, 3);
}

TEST(Cache2Q, TestThree) {
  bool res;
  size_t cache_capacity, request_num;
  int num, num_of_hits = 0;
  std::ifstream in;
  in.open("../../tests/files_for_tests/004.dat");
  in >> cache_capacity >> request_num;
  cache_2q<int> cache(cache_capacity);
  for (size_t i = 0; i < request_num; ++i) {
    in >> num;
    res = cache.query(num);
    num_of_hits += res;
    if (!res) {
      cache.push(num);
    }
  }
  in.close();
  EXPECT_EQ(num_of_hits, 10);
}

TEST(Cache2Q, TestFour) {
  bool res;
  size_t cache_capacity, request_num;
  int num, num_of_hits = 0;
  std::ifstream in;
  in.open("../../tests/files_for_tests/005.dat");
  in >> cache_capacity >> request_num;
  cache_2q<int> cache(cache_capacity);
  for (size_t i = 0; i < request_num; ++i) {
    in >> num;
    res = cache.query(num);
    num_of_hits += res;
    if (!res) {
      cache.push(num);
    }
  }
  in.close();
  EXPECT_EQ(num_of_hits, 32);
}

TEST(Cache2Q, TestFive) {
  bool res;
  size_t cache_capacity, request_num;
  int num, num_of_hits = 0;
  std::ifstream in;
  in.open("../../tests/files_for_tests/006.dat");
  in >> cache_capacity >> request_num;
  cache_2q<int> cache(cache_capacity);
  for (size_t i = 0; i < request_num; ++i) {
    in >> num;
    res = cache.query(num);
    num_of_hits += res;
    if (!res) {
      cache.push(num);
    }
  }
  in.close();
  EXPECT_EQ(num_of_hits, 187);
}

TEST(Cache2Q, TestSix) {
  bool res;
  size_t cache_capacity, request_num;
  int num, num_of_hits = 0;
  std::ifstream in;
  in.open("../../tests/files_for_tests/007.dat");
  in >> cache_capacity >> request_num;
  cache_2q<int> cache(cache_capacity);
  for (size_t i = 0; i < request_num; ++i) {
    in >> num;
    res = cache.query(num);
    num_of_hits += res;
    if (!res) {
      cache.push(num);
    }
  }
  in.close();
  EXPECT_EQ(num_of_hits, 469);
}

TEST(Cache2Q, TestSeven) {
  bool res;
  size_t cache_capacity, request_num;
  int num, num_of_hits = 0;
  std::ifstream in;
  in.open("../../tests/files_for_tests/008.dat");
  in >> cache_capacity >> request_num;
  cache_2q<int> cache(cache_capacity);
  for (size_t i = 0; i < request_num; ++i) {
    in >> num;
    res = cache.query(num);
    num_of_hits += res;
    if (!res) {
      cache.push(num);
    }
  }
  in.close();
  EXPECT_EQ(num_of_hits, 3301);
}

TEST(Cache2Q, TestEight) {
  bool res;
  size_t cache_capacity, request_num;
  int num, num_of_hits = 0;
  std::ifstream in;
  in.open("../../tests/files_for_tests/009.dat");
  in >> cache_capacity >> request_num;
  cache_2q<int> cache(cache_capacity);
  for (size_t i = 0; i < request_num; ++i) {
    in >> num;
    res = cache.query(num);
    num_of_hits += res;
    if (!res) {
      cache.push(num);
    }
  }
  in.close();
  EXPECT_EQ(num_of_hits, 953);
}

TEST(Cache2Q, TestNine) {
  bool res;
  size_t cache_capacity, request_num;
  int num, num_of_hits = 0;
  std::ifstream in;
  in.open("../../tests/files_for_tests/010.dat");
  in >> cache_capacity >> request_num;
  cache_2q<int> cache(cache_capacity);
  for (size_t i = 0; i < request_num; ++i) {
    in >> num;
    res = cache.query(num);
    num_of_hits += res;
    if (!res) {
      cache.push(num);
    }
  }
  in.close();
  EXPECT_EQ(num_of_hits, 4984);
}

TEST(Cache2Q, TestTen) {
  bool res;
  size_t cache_capacity, request_num;
  int num, num_of_hits = 0;
  std::ifstream in;
  in.open("../../tests/files_for_tests/011.dat");
  in >> cache_capacity >> request_num;
  cache_2q<int> cache(cache_capacity);
  for (size_t i = 0; i < request_num; ++i) {
    in >> num;
    res = cache.query(num);
    num_of_hits += res;
    if (!res) {
      cache.push(num);
    }
  }
  in.close();
  EXPECT_EQ(num_of_hits, 89999);
}

TEST(Cache2Q, TestEleven) {
  bool res;
  size_t cache_capacity, request_num;
  int num, num_of_hits = 0;
  std::ifstream in;
  in.open("../../tests/files_for_tests/012.dat");
  in >> cache_capacity >> request_num;
  cache_2q<int> cache(cache_capacity);
  for (size_t i = 0; i < request_num; ++i) {
    in >> num;
    res = cache.query(num);
    num_of_hits += res;
    if (!res) {
      cache.push(num);
    }
  }
  in.close();
  EXPECT_EQ(num_of_hits, 110508);
}

TEST(Cache2Q, TestTwelve) {
  bool res;
  size_t cache_capacity, request_num;
  int num, num_of_hits = 0;
  std::ifstream in;
  in.open("../../tests/files_for_tests/013.dat");
  in >> cache_capacity >> request_num;
  cache_2q<int> cache(cache_capacity);
  for (size_t i = 0; i < request_num; ++i) {
    in >> num;
    res = cache.query(num);
    num_of_hits += res;
    if (!res) {
      cache.push(num);
    }
  }
  in.close();
  EXPECT_EQ(num_of_hits, 298999);
}

TEST(Cache2Q, TestThirteen) {
  bool res;
  size_t cache_capacity, request_num;
  int num, num_of_hits = 0;
  std::ifstream in;
  in.open("../../tests/files_for_tests/014.dat");
  in >> cache_capacity >> request_num;
  cache_2q<int> cache(cache_capacity);
  for (size_t i = 0; i < request_num; ++i) {
    in >> num;
    res = cache.query(num);
    num_of_hits += res;
    if (!res) {
      cache.push(num);
    }
  }
  in.close();
  EXPECT_EQ(num_of_hits, 389999);
}

TEST(Cache2Q, TestFourteen) {
  bool res;
  size_t cache_capacity, request_num;
  int num, num_of_hits = 0;
  std::ifstream in;
  in.open("../../tests/files_for_tests/015.dat");
  in >> cache_capacity >> request_num;
  cache_2q<int> cache(cache_capacity);
  for (size_t i = 0; i < request_num; ++i) {
    in >> num;
    res = cache.query(num);
    num_of_hits += res;
    if (!res) {
      cache.push(num);
    }
  }
  in.close();
  EXPECT_EQ(num_of_hits, 75141);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}