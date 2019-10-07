#ifndef DEQUE_H
#define DEQUE_H

#include "node.h"

template <typename T>
class Deque
{
public:
  Deque();
  ~Deque();
  // note, needs copy constructor
  bool isEmpty() const {return (first_ == last_);}
  int size() const {return sz_;}
  void addFirst(T item);
  void addLast(T item);
  T removeFirst();
  T removeLast();
private:
  Node<T>* first_;
  Node<T>* last_;
  int sz_;
};

template <typename T>
Deque<T>::Deque()
  : first_(nullptr),
    last_(nullptr),
    sz_(0) {}

template <typename T>
void Deque<T>::addFirst(T item)
{
  Node<T>* old_first = first_;
  first_ = new Node<T>(item);
  first_->next = old_first;

  if (old_first)
  {
    old_first->prev = first_;
  }

  if (!last_)
  {
    last_ = first_;
  }
  sz_++;
}

template <typename T>
void Deque<T>::addLast(T item)
{
  Node<T>* old_last = last_;
  last_ = new Node<T>(item);
  last_->prev = old_last;

  if (old_last)
  {
    old_last->next = last_;
  }

  if (!first_)
  {
    first_ = last_;
  }
  sz_++;
}

template <typename T>
T Deque<T>::removeFirst()
{
  Node<T>* old_first = first_;

  if (old_first->next)
  {
    first_ = old_first->next;
    first_->prev = nullptr;
  }
  else  // empty
  {
    first_ = nullptr;
    last_ = nullptr;
  }

  sz_--;
  T old_first_item = old_first->item;
  delete old_first;

  return old_first_item;
}

template <typename T>
T Deque<T>::removeLast()
{
  Node<T>* old_last = last_;

  if (old_last->prev)
  {
    last_ = old_last->prev;
    last_->next = nullptr;
  }
  else // empty
  {
    last_ = nullptr;
    first_ = nullptr;
  }

  sz_--;
  T old_last_item = old_last->item;
  delete old_last;

  return old_last_item;
}

template <typename T>
Deque<T>::~Deque()
{
  while (first_)
  {
    removeFirst();
  }
}

#endif  // DEQUE_H
