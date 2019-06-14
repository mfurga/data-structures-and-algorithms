#ifndef BINARY_MAX_HEAP_H
#define BINARY_MAX_HEAP_H

#include <memory>
#include <optional>

#define BINARY_MAX_HEAP_CAPACITY 256

namespace mf
{

class MaxHeap
{
 private:
  size_t size_;
  int capacity_;
  int *array_;

  static void sift_up(int *array, size_t size, int index);
  static void sift_down(int *array, size_t size, int index);

 public:
  MaxHeap();
  ~MaxHeap();

  void heapify(int *array, size_t size);
  static void heapsort(int *array, size_t size);

  void insert(int value);
  std::optional<int> extract_max();
  std::optional<int> get_max() const;
};

}

#endif  // BINARY_MAX_HEAP_H
