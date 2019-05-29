#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#include <memory>
#include <optional>

namespace mf
{

template <class T>
class Queue
{
 private:
  int read_;
  int write_;
  int capacity_;
  std::unique_ptr<T[]> array_;
 
 public:
  Queue(int capacity) : read_(0), write_(0), capacity_(capacity + 1) {
    array_ = std::unique_ptr<T[]>(new T[capacity_]);
  }
  ~Queue() {};

  void enqueue(T value);
  std::optional<const T> dequeue();
};

}  // namespace mf

#endif  // QUEUE_ARRAY_H
