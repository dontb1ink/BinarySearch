#include "BinarySearch.h"

int BinarySearch::search(int x, int *array, int n) {
  int mid;

  mid = n / 2;
  if (array[mid] == x) {
    return mid;
  } else if (mid == 0) {
    return -1;
  } else if (array[mid] > x) {
    return search(x, array, mid);
  } else {
    return search(x, &array[mid + 1], n - mid - 1) + mid + 1;
  }
}
