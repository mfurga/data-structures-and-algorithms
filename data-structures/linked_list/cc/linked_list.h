#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <optional>

namespace mf
{

template <class T>
class LinkedListNode
{
 private:
  T value_;
  LinkedListNode<T> *prev_;
  LinkedListNode<T> *next_;

 public:
  LinkedListNode(const T &value) : value_(value), prev_(nullptr), next_(nullptr) {}
  ~LinkedListNode() {}

  const T &get_value() const { return value_; }
  LinkedListNode<T> *get_next() const { return next_; }
  LinkedListNode<T> *get_prev() const { return prev_; }

  void set_value(const T &value) { value_ = value; }
  void set_next(LinkedListNode<T> *next) { next_ = next; }
  void set_prev(LinkedListNode<T> *prev) { prev_ = prev; }
};

template <class T>
class LinkedList
{
 private:
  LinkedListNode<T> *head_;
  LinkedListNode<T> *tail_;

 public:
  LinkedList() : head_(nullptr), tail_(nullptr) {}
  ~LinkedList();
  LinkedList(const LinkedList &) = delete;
  LinkedList &operator=(const LinkedList &) = delete;

  int size() const;
  bool is_empty() const;

  std::optional<T> value_at(int index) const;

  void push_front(T value);
  std::optional<const T> pop_front();

  void push_back(T value);
  std::optional<const T> pop_back();

  std::optional<const T> front() const;
  std::optional<const T> back() const;

  void insert(int index, T value);
  void erase(int index);

  void reverse();
};

}  // namespace mf

#endif  // LINKED_LIST_H
