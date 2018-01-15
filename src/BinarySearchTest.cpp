#include <cstdlib>
#include <iostream>
#include "BinarySearch.h"
#include "gtest/gtest.h"

#define DEBUG 0

using namespace std;

class BinarySearchTest : public ::testing::Test {
 protected:
  BinarySearchTest() {}
  ~BinarySearchTest() {}
  static const int SEED = 43;
  static const int MAX_VARIANCE = 32;
  BinarySearch binary_search;
  void test_actual_expected(int x, int *array, int n) {
    int i, actual, expected;

    expected = -1;
#if DEBUG
    cout << "Array: [";
#endif
    for (i = 0; i < n; i++) {
#if DEBUG
      cout << array[i] << ((i == n - 1) ? "" : ",");
#endif
      if (x == array[i]) expected = i;
    }
#if DEBUG
    cout << "], ";
#endif

    actual = binary_search.search(x, array, n);
#if DEBUG
    cout << "Search: " << actual << ", Value: " << x << endl;
#endif
    EXPECT_EQ(actual, expected);
  }
  static void generate_random_sorted_array(int *in, int n) {
    int i;

    srand(SEED);
    i = 0;
    in[i++] = rand() % MAX_VARIANCE;
    for (; i < n; i++) {
      in[i] = in[i - 1] + rand() % MAX_VARIANCE + 1;
    }
  }
  static void generate_sequential_array(int *in, int n) {
    int i;

    for (i = 0; i < n; i++) {
      in[i] = i;
    }
  }
};

TEST_F(BinarySearchTest, Random1ArrayRandomTarget) {
  const int n = 1;
  int array[n];
  int target;

  generate_random_sorted_array(&array[0], n);
  target = array[rand() % n];
  test_actual_expected(target, array, n);
}

TEST_F(BinarySearchTest, Random1ArrayInvalidTarget) {
  const int n = 1;
  int array[n];
  int target;

  generate_random_sorted_array(&array[0], n);
  target = array[0] + 1;
  test_actual_expected(target, array, n);
}

TEST_F(BinarySearchTest, Random2ArrayRandomTarget) {
  const int n = 2;
  int array[n];
  int target;

  generate_random_sorted_array(&array[0], n);
  target = array[rand() % n];
  test_actual_expected(target, array, n);
}

TEST_F(BinarySearchTest, Random3ArrayRandomTarget) {
  const int n = 3;
  int array[n];
  int target;

  generate_random_sorted_array(&array[0], n);
  target = array[rand() % n];
  test_actual_expected(target, array, n);
}

TEST_F(BinarySearchTest, Random4ArrayRandomTarget) {
  const int n = 4;
  int array[n];
  int target;

  generate_random_sorted_array(&array[0], n);
  target = array[rand() % n];
  test_actual_expected(target, array, n);
}

TEST_F(BinarySearchTest, Random5ArrayRandomTarget) {
  const int n = 5;
  int array[n];
  int target;

  generate_random_sorted_array(&array[0], n);
  target = array[rand() % n];
  test_actual_expected(target, array, n);
}

TEST_F(BinarySearchTest, Random500ArrayRandomTarget) {
  const int n = 500;
  int array[n];
  int target;

  generate_random_sorted_array(&array[0], n);
  target = array[rand() % n];
  test_actual_expected(target, array, n);
}

TEST_F(BinarySearchTest, Random500ArrayFirstIndexTarget) {
  const int n = 500;
  int array[n];
  int target;

  generate_random_sorted_array(&array[0], n);
  target = array[0];
  test_actual_expected(target, array, n);
}

TEST_F(BinarySearchTest, Random500ArrayLastIndexTarget) {
  const int n = 500;
  int array[n];
  int target;

  generate_random_sorted_array(&array[0], n);
  target = array[n - 1];
  test_actual_expected(target, array, n);
}

TEST_F(BinarySearchTest, Random501ArrayFirstIndexTarget) {
  const int n = 501;
  int array[n];
  int target;

  generate_random_sorted_array(&array[0], n);
  target = array[0];
  test_actual_expected(target, array, n);
}

TEST_F(BinarySearchTest, Random501ArrayLastIndexTarget) {
  const int n = 501;
  int array[n];
  int target;

  generate_random_sorted_array(&array[0], n);
  target = array[n - 1];
  test_actual_expected(target, array, n);
}

TEST_F(BinarySearchTest, Sequential501ArrayFirstIndexTarget) {
  const int n = 501;
  int array[n];
  int target;

  generate_sequential_array(&array[0], n);
  target = array[0];
  test_actual_expected(target, array, n);
}

TEST_F(BinarySearchTest, Sequential501ArrayLastIndexTarget) {
  const int n = 501;
  int array[n];
  int target;

  generate_sequential_array(&array[0], n);
  target = array[n - 1];
  test_actual_expected(target, array, n);
}

TEST_F(BinarySearchTest, Sequential501ArrayMidIndexTarget) {
  const int n = 501;
  int array[n];
  int target;

  generate_sequential_array(&array[0], n);
  target = array[n / 2];
  test_actual_expected(target, array, n);
}

TEST_F(BinarySearchTest, Sequential500ArrayMidIndexTarget) {
  const int n = 500;
  int array[n];
  int target;

  generate_sequential_array(&array[0], n);
  target = array[n / 2];
  test_actual_expected(target, array, n);
}

TEST_F(BinarySearchTest, Sequential499ArrayMidIndexTarget) {
  const int n = 500;
  int array[n];
  int target;

  generate_sequential_array(&array[0], n);
  target = array[n / 2];
  test_actual_expected(target, array, n);
}

TEST_F(BinarySearchTest, Sequential10000ArrayRandomTarget) {
  const int n = 10000;
  int array[n];
  int target;

  generate_sequential_array(&array[0], n);
  target = array[rand() % n];
  test_actual_expected(target, array, n);
}

TEST_F(BinarySearchTest, Random10000ArrayRandomTarget) {
  const int n = 10000;
  int array[n];
  int target;

  generate_random_sorted_array(&array[0], n);
  target = array[rand() % n];
  ;
  test_actual_expected(target, array, n);
}

TEST_F(BinarySearchTest, Random1000000ArrayRandomTarget) {
  const int n = 1000000;
  int array[n];
  int target;

  generate_random_sorted_array(&array[0], n);
  target = array[rand() % n];
  test_actual_expected(target, array, n);
}
