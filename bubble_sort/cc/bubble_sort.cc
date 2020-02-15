#include <iostream>

template <typename T=int>
void bubble_sort(T *arr, size_t sz)
{
  for (size_t i = 0; i < sz; i++) {
    for (size_t j = 1; j < sz - i; j++) {
      if (arr[j - 1] > arr[j]) {
        std::swap(arr[j - 1], arr[j]);
      }
    }
  }
}

int main()
{
  int arr[] = {5, -1, 3, 8, -4, 0};
  size_t sz = 6;

  bubble_sort<>(arr, sz);

  return 0;
}
