#include <iostream>

#include "deque.h"

int main(int argc, char* argv[])
{
  Deque<int> numbers;

  std::cout << "Numbers is " << (numbers.isEmpty() ? "empty" : "not empty") << std::endl;
  // Empty add
  numbers.addFirst(1);
  std::cout << "First is " << numbers.removeFirst() << std::endl;
  numbers.addLast(2);
  std::cout << "Last is " << numbers.removeLast() << std::endl;

  numbers.addFirst(1);
  numbers.addLast(2);
  std::cout << "Numbers is " << (numbers.isEmpty() ? "empty" : "not empty") << std::endl;
  std::cout << "Size is " << numbers.size() << std::endl;

  std::cout << "First is " << numbers.removeFirst() << std::endl;
  std::cout << "Last is " << numbers.removeLast() << std::endl;
}
