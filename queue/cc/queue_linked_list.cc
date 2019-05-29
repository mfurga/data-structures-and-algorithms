#include <iostream>
#include "queue_linked_list.h"

namespace mf
{

template <class T>
Queue<T>::~Queue()
{
  QueueNode<T> *current = head_;
  QueueNode<T> *next = nullptr;

  while (current != nullptr) {
    next = current->get_next();
    delete current;
    current = next;
  }
}

template <class T>
void Queue<T>::enqueue(T value)
{
  QueueNode<T> *node = new QueueNode<T>(value);
  node->set_next(nullptr);

  if (head_ == nullptr)
    head_ = node;
  else
    tail_->set_next(node);

  tail_ = node;
}

template <class T>
std::optional<const T> Queue<T>::dequeue()
{
  if (head_ == nullptr)
    return std::nullopt;

  QueueNode<T> *node = head_;
  T value = node->get_value();

  head_ = head_->get_next();
  if (head_ == nullptr)
    tail_ = nullptr;

  delete node;
  return value;
}

}  // namespace mf
