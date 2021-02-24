#ifndef QUEUE_LINKED_LIST_H
#define QUEUE_LINKED_LIST_H

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
  const T dequeue();
  bool is_empty() const;
};

#endif  // QUEUE_LINKED_LIST_H

/* Source */

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
const T Queue<T>::dequeue()
{
  QueueNode<T> *node = head_;
  T value = node->get_value();

  head_ = head_->get_next();
  if (head_ == nullptr)
    tail_ = nullptr;

  delete node;
  return value;
}

template <class T>
bool Queue<T>::is_empty() const
{
  return head_ == nullptr;
}
