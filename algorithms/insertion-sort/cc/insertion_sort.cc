#include <iostream>

template <typename T>
void insertion_sort(T arr[], size_t size)
{
  int j = 1;
  for (size_t i = 1; i < size; i++) {
    j = i;
    int key = arr[j];

    while (j > 0 && arr[j - 1] < key) {
      arr[j] = arr[j - 1];
      j--;
    }

    arr[j] = key;
  }
}

int main()
{
  int arr[] = {5, 1, 3, -10, 2, 4};
  size_t n = 6;

  insertion_sort<int>(arr, n);

  return 0;
}