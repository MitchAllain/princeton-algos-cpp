#ifndef RANDOMIZED_QUEUE_H
#define RANDOMIZED_QUEUE_H

template <typename T>
class RandomizedQueue
{
public:
  RandomizedQueue();
  ~RandomizedQueue();
  bool isEmpty() {return (length_ == 0);}
  int size() {return length_;}
  void enqueue(T item);
  T dequeue();
  T sample();
private:
  int sz_;
  int length_;
  T* array_;
  void resize(int size);
};

template <typename T>
RandomizedQueue<T>::RandomizedQueue()
  : sz_(2),
    array_{new T[sz_]}
{
  srand(time(NULL));
}

template <typename T>
RandomizedQueue<T>::~RandomizedQueue()
{
  delete[] array_;
}

template <typename T>
void RandomizedQueue<T>::enqueue(T item)
{
  array_[length_] = item;
  length_++;

  if (length_ == sz_) resize(sz_ * 2);
}

template <typename T>
T RandomizedQueue<T>::dequeue()
{
  // draw random number i from 0 to l - 1
  int i = std::rand() % (length_ - 1);

  // remove drawn item and replace from end of array
  T old_item = array_[i];
  array_[i] = array_[length_ - 1];
  length_--;

  if ((length_ > 0) && (length_ == sz_ / 4)) resize(sz_ / 2);

  return old_item;
}

template <typename T>
void RandomizedQueue<T>::resize(int size)
{
  T* new_array = new T[size];
  std::copy(array_, array_ + std::min(sz_, size), new_array);
  delete[] array_;

  array_ = new_array;
  sz_ = size;
}

#endif  // RANDOMIZED_QUEUE_H
