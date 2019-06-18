#include <iostream>

template <typename T>
void insertion_sort(T arr[], int size)
{
  int j = 1;
  for (int i = 1; i < size; i++) {
    j = i;
    while (j > 0 && arr[j] < arr[j - 1]) {
      std::swap(arr[j], arr[j - 1]);
      j--;
    }
  }
}
