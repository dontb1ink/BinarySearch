#include <iostream>
#include "BinarySearch.h"

using namespace std;

int main() {
  int value = 30; 
  const int size = 6;
  int data[size] { 15, 30, 45, 60, 75, 90 };

  BinarySearch bs;
  cout << bs.search(value, &data[0], size) << endl;
}
