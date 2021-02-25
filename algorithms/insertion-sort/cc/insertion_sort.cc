#include <iostream>

template <typename T>
void insertion_sort(T arr[], int size)
{
  for (int i = 1; i < size; i++) {
    T key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = key;
  }
}

int main()
{
  int arr[] = {5, 2, 4, 6, 1, 3};
  insertion_sort<int>(arr, 6);
  return 0;
}

