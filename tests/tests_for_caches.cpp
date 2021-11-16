#include <iostream>
#include <stdio.h>
#include "gtest/gtest.h"
#include "../Cache/includes/ideal_cache.hpp"
#include "../Cache/includes/ideal_cache_impl.hpp"
#include "../Cache/includes/cache_2q.hpp"
#include "../Cache/includes/cache_2q_impl.hpp"

TEST(IdealCache, TestOne) {
    size_t cache_capacity, request_num;
    FILE* f;
    f = fopen("../../tests/files_for_tests/001.dat","r");
    fscanf(f, "%lu%lu", &cache_capacity, &request_num);
    ideal_cache<int> cache(cache_capacity, request_num);
    cache.get_request_arr(true, f);
    fclose(f);
    cache.start_work();
    EXPECT_EQ(cache.number_of_hits(), 4);
}

TEST(IdealCache, TestTwo) {
    size_t cache_capacity, request_num;
    FILE* f;
    f = fopen("../../tests/files_for_tests/002.dat","r");
    fscanf(f, "%lu%lu", &cache_capacity, &request_num);
    ideal_cache<int> cache(cache_capacity, request_num);
    cache.get_request_arr(true, f);
    fclose(f);
    cache.start_work();
    EXPECT_EQ(cache.number_of_hits(), 0);
}

TEST(IdealCache, TestThree) {
    size_t cache_capacity, request_num;
    FILE* f;
    f = fopen("../../tests/files_for_tests/003.dat","r");
    fscanf(f, "%lu%lu", &cache_capacity, &request_num);
    ideal_cache<int> cache(cache_capacity, request_num);
    cache.get_request_arr(true, f);
    fclose(f);
    cache.start_work();
    EXPECT_EQ(cache.number_of_hits(), 6);
}

TEST(IdealCache, TestFour) {
    size_t cache_capacity, request_num;
    FILE* f;
    f = fopen("../../tests/files_for_tests/004.dat","r");
    fscanf(f, "%lu%lu", &cache_capacity, &request_num);
    ideal_cache<int> cache(cache_capacity, request_num);
    cache.get_request_arr(true, f);
    fclose(f);
    cache.start_work();
    EXPECT_EQ(cache.number_of_hits(), 17);
}

TEST(IdealCache, TestFive) {
    size_t cache_capacity, request_num;
    FILE* f;
    f = fopen("../../tests/files_for_tests/005.dat","r");
    fscanf(f, "%lu%lu", &cache_capacity, &request_num);
    ideal_cache<int> cache(cache_capacity, request_num);
    cache.get_request_arr(true, f);
    fclose(f);
    cache.start_work();
    EXPECT_EQ(cache.number_of_hits(), 63);
}

TEST(IdealCache, TestSix) {
    size_t cache_capacity, request_num;
    FILE* f;
    f = fopen("../../tests/files_for_tests/006.dat","r");
    fscanf(f, "%lu%lu", &cache_capacity, &request_num);
    ideal_cache<int> cache(cache_capacity, request_num);
    cache.get_request_arr(true, f);
    fclose(f);
    cache.start_work();
    EXPECT_EQ(cache.number_of_hits(), 327);
}

TEST(IdealCache, TestSeven) {
    size_t cache_capacity, request_num;
    FILE* f;
    f = fopen("../../tests/files_for_tests/007.dat","r");
    fscanf(f, "%lu%lu", &cache_capacity, &request_num);
    ideal_cache<int> cache(cache_capacity, request_num);
    cache.get_request_arr(true, f);
    fclose(f);
    cache.start_work();
    EXPECT_EQ(cache.number_of_hits(), 742);
}

TEST(IdealCache, TestEight) {
    size_t cache_capacity, request_num;
    FILE* f;
    f = fopen("../../tests/files_for_tests/008.dat","r");
    fscanf(f, "%lu%lu", &cache_capacity, &request_num);
    ideal_cache<int> cache(cache_capacity, request_num);
    cache.get_request_arr(true, f);
    fclose(f);
    cache.start_work();
    EXPECT_EQ(cache.number_of_hits(), 6706);
}

TEST(IdealCache, TestNine) {
    size_t cache_capacity, request_num;
    FILE* f;
    f = fopen("../../tests/files_for_tests/009.dat","r");
    fscanf(f, "%lu%lu", &cache_capacity, &request_num);
    ideal_cache<int> cache(cache_capacity, request_num);
    cache.get_request_arr(true, f);
    fclose(f);
    cache.start_work();
    EXPECT_EQ(cache.number_of_hits(), 3846);
}

TEST(IdealCache, TestTen) {
    size_t cache_capacity, request_num;
    FILE* f;
    f = fopen("../../tests/files_for_tests/010.dat","r");
    fscanf(f, "%lu%lu", &cache_capacity, &request_num);
    ideal_cache<int> cache(cache_capacity, request_num);
    cache.get_request_arr(true, f);
    fclose(f);
    cache.start_work();
    EXPECT_EQ(cache.number_of_hits(), 19680);
}


int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}