#include <iostream>

#include "randomized_queue.h"

int main(int argc, char* argv[])
{
  RandomizedQueue<int> r_numbers;

  std::cout << "r_Numbers is " << (r_numbers.isEmpty() ? "empty" : "not empty") << std::endl;
  for (int i = 0; i < 100; i++)
  {
    r_numbers.enqueue(i);
  }
  std::cout << "r_Numbers is " << (r_numbers.isEmpty() ? "empty" : "not empty") << std::endl;
  std::cout << "Size is " << r_numbers.size() << std::endl;

  std::cout << "Dequeued " << r_numbers.dequeue() << std::endl;
  std::cout << "Dequeued " << r_numbers.dequeue() << std::endl;
  std::cout << "Dequeued " << r_numbers.dequeue() << std::endl;
}
