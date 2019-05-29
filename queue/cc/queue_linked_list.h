#ifndef QUEUE_LINKED_LIST_H
#define QUEUE_LINKED_LIST_H

#include <optional>

namespace mf
{
template <class T>
class QueueNode
{
 private:
  T value_;
  QueueNode<T> *next_;

 public:
  QueueNode(const T &value) : value_(value), next_(nullptr) {}
  ~QueueNode() {}

  const T &get_value() const { return value_; }
  QueueNode<T> *get_next() const { return next_; }

  void set_value(const T &value) { value_ = value; }
  void set_next(QueueNode<T> *next) { next_ = next; }
};

template <class T>
class Queue
{
 private:
  QueueNode<T> *head_;
  QueueNode<T> *tail_;
 
 public:
  Queue() : head_(nullptr), tail_(nullptr) {}
  ~Queue();

  void enqueue(T value);
  std::optional<const T> dequeue();
};

}  // namespace mf

#endif  // QUEUE_LINKED_LIST_H
