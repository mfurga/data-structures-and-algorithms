#include "linked_list.h"

namespace mf
{

template <class T>
LinkedList<T>::~LinkedList()
{
  LinkedListNode<T> *current = head_;
  LinkedListNode<T> *next = nullptr;

  while (current) {
    next = current->get_next();
    delete current;
    current = next;
  }
}

template <class T>
int LinkedList<T>::size() const
{
  int count = 0;
  for (LinkedListNode<T> *i = head_; i != nullptr; i = i->get_next()) {
    count++;
  }
  return count;
}

template <class T>
bool LinkedList<T>::is_empty() const
{
  return head_ == nullptr;
}

template <class T>
std::optional<T> LinkedList<T>::value_at(int index) const
{
  if (index < 0 || index >= this->size())
    return std::nullopt;

  LinkedListNode<T> *node = head_;
  for (int i = 0; i != index; i++, node = node->get_next());

  return node->get_value();
}

template <class T>
void LinkedList<T>::push_front(T value)
{
  LinkedListNode<T> *node = new LinkedListNode<T>(value);
  node->set_prev(nullptr);
  node->set_next(head_);

  if (head_ == nullptr)
    tail_ = node;
  else
    head_->set_prev(node);

  head_ = node;
}

template <class T>
std::optional<const T> LinkedList<T>::pop_front()
{
  if (head_ == nullptr)
    return std::nullopt;

  LinkedListNode<T> *node = head_;
  T value = node->get_value();

  head_ = head_->get_next();
  if (head_ == nullptr)
    tail_ = nullptr;
  else
    head_->set_prev(nullptr);

  delete node;
  return value;
}

template <class T>
void LinkedList<T>::push_back(T value)
{
  LinkedListNode<T> *node = new LinkedListNode<T>(value);
  node->set_prev(tail_);
  node->set_next(nullptr);

  if (head_ == nullptr)
    head_ = node;
  else
    tail_->set_next(node);

  tail_ = node;
}

template <class T>
std::optional<const T> LinkedList<T>::pop_back()
{
  if (head_ == nullptr)
    return std::nullopt;

  LinkedListNode<T> *node = tail_;
  T value = node->get_value();

  tail_ = tail_->get_prev();
  if (tail_ == nullptr)
    head_ = nullptr;
  else
    tail_->set_next(nullptr);

  delete node;
  return value;
}

template <class T>
std::optional<const T> LinkedList<T>::front() const
{
  if (head_ == nullptr)
    return std::nullopt;
  return head_->get_value();
}

template <class T>
std::optional<const T> LinkedList<T>::back() const
{
  if (head_ == nullptr)
    return std::nullopt;
  return tail_->get_value();
}

template <class T>
void LinkedList<T>::insert(int index, T value)
{
  if (index < 0 || index >= this->size())
    return;

  LinkedListNode<T> *node = new LinkedListNode<T>(value);
  LinkedListNode<T> *in = head_;
  for (int i = 0; i != index; i++, in = in->get_next());

  node->set_next(in);
  node->set_prev(in->get_prev());

  if (in->get_prev() == nullptr)
    head_ = node;
  else
    in->get_prev()->set_next(node);

  in->set_prev(node);
}

template <class T>
void LinkedList<T>::erase(int index)
{
  if (index < 0 || index >= this->size())
    return;
  
  LinkedListNode<T> *in = head_;
  for (int i = 0; i != index; i++, in = in->get_next());

  if (in->get_prev() == nullptr)
    head_ = in->get_next();
  else
    in->get_prev()->set_next(in->get_next());

  if (in->get_next() == nullptr)
    tail_ = in->get_prev();
  else
    in->get_next()->set_prev(in->get_prev());

  delete in;
}

template <class T>
void LinkedList<T>::reverse()
{
  if (head_ == nullptr || head_->get_next() == nullptr)
    return;

  tail_ = head_;
  LinkedListNode<T> *tmp = nullptr;

  for (LinkedListNode<T> *i = head_; i != nullptr; i = i->get_prev()) {
    tmp = i->get_prev();
    i->set_prev(i->get_next());
    i->set_next(tmp);
  }

  head_ = tmp->get_prev();
}

}  // namespace mf
