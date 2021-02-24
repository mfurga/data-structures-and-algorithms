#include "queue_array.h"

namespace mf
{

template <class T>
void Queue<T>::enqueue(T value)
{
  if ((write_ + 1) % capacity_ == read_)
    return;

  array_[write_] = value;
  write_ = (write_ + 1) % capacity_;
}

template <class T>
std::optional<const T> Queue<T>::dequeue()
{
  if (write_ == read_)
    return std::nullopt;

  T res = array_[read_];
  read_ = (read_ + 1) % capacity_;
  return res;
}

}  // namespace mf
