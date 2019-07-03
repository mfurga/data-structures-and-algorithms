#ifndef LINKED_LIST_H
#define LINKED_LIST_H

namespace linked_list
{

template <class T>
struct LinkedListNode
{
  T value;
  LinkedListNode<T> *prev;
  LinkedListNode<T> *next;

  LinkedListNode(const T &value) : value(value), prev(nullptr), next(nullptr) {}
  ~LinkedListNode() {}
};

template <class T>
class LinkedList
{
 private:
  LinkedListNode<T> *head_;
  LinkedListNode<T> *tail_;

 public:
  LinkedList() : head_(nullptr), tail_(nullptr) {}
  LinkedList(const LinkedList &) = delete;
  ~LinkedList() {
    LinkedListNode<T> *current = head_;
    LinkedListNode<T> *next = nullptr;

    while (current) {
      next = current->next;
      delete current;
      current = next;
    }
  }

  LinkedListNode<T> *head() { 
    return head_;
  };

  inline bool empty() const {
    return head_ == nullptr;
  }

  void push_back(const T& value) {
    LinkedListNode<T> *node = new LinkedListNode<T>(value);
    node->prev = tail_;
    node->next = nullptr;

    if (head_ == nullptr)
      head_ = node;
    else
      tail_->next = node;

    tail_ = node;
  }

  void erase(const T& value) {
    LinkedListNode<T> *current;
    for (current = head_; current != nullptr && current->value != value; 
         current = current->next);
    if (current == nullptr)
      return;

    if (current->prev == nullptr)
      head_ = current->next;
    else
      current->prev->next = current->next;

    if (current->next == nullptr)
      tail_ = current->prev;
    else
      current->next->prev = current->prev;

    delete current;
  }

};

}  // namespace linked_list

#endif  // LINKED_LIST_H
