#include <cstdlib>
#include "heap.h"

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

namespace mf
{

MaxHeap::MaxHeap() : size_(0), capacity_(BINARY_MAX_HEAP_CAPACITY)
{
  array_ = new int[capacity_];
}

MaxHeap::~MaxHeap()
{
  delete[] array_;
}

void MaxHeap::sift_up(int *array, size_t size, int index)
{
  while (index > 0 && array[index] > array[index / 2]) {
    /* Now we need to swap the values (change their priority). */
    std::swap(array[index], array[index / 2]);
    index /= 2;
  }
}

void MaxHeap::sift_down(int *array, size_t size, int index)
{
  int max_index = index;
  /* Check if the left child exists and compare. */
  if ((index * 2 + 1) < size && array[index * 2 + 1] > array[max_index]) {
    max_index = index * 2 + 1;
  }

  /* Check if the right child exists and compare. */
  if ((index * 2 + 2) < size && array[index * 2 + 2] > array[max_index]) {
    max_index = index * 2 + 2;
  }

  if (index != max_index) {
    std::swap(array[index], array[max_index]);
    sift_down(array, size, max_index);
  }
}

void MaxHeap::insert(int value)
{
  if (size_ - 1 == capacity_)
    return;  /* Heap is full. */

  array_[size_++] = value;
  sift_up(array_, size_, size_ - 1);
}

std::optional<int> MaxHeap::extract_max()
{
  if (size_ == 0)
    return std::nullopt;  /* Heap is empty. */

  int res = array_[0];
  array_[0] = array_[--size_];
  sift_down(array_, size_, 0);
  return res;
}

std::optional<int> MaxHeap::get_max() const
{
  if (size_ == 0)
    return std::nullopt;  /* Heap is empty. */
  return array_[0];
}

void MaxHeap::heapify(int *array, size_t size)
{
  memcpy(array_, array, sizeof(int) * size);
  size_ = size;

  for (int j = size_ / 2 - 1; j >= 0; j--) {
    sift_down(array_, size_, j);
  }
}

void MaxHeap::heapsort(int *array, size_t size)
{
  for (int i = size / 2 - 1; i >= 0; i--) {
    sift_down(array, size, i);
  }

  for (int j = size - 1; j > 0; j--) {
    std::swap(array[0], array[j]);
    sift_down(array, j, 0);
  }
}

}  // namespace mf
