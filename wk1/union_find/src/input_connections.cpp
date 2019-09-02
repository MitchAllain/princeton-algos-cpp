#include "abstract_uf.h"
#include "quick_find_uf.h"
#include "quick_union_uf.h"

#include <iostream>
#include <memory>

int main()
{
  int n;
  std::cin >> n;

  // pretending there is some kind of runtime strategy selection here
  QuickUnionUF uf(n);

  // interact with data types through the abstract interface
  AbstractUF* auf = &uf;

  while (true)
  {
    int p;
    int q;
    std::cin >> p >> q;

    if (!auf->connected(p, q))
    {
      auf->connect(p, q);
      std::cout << p << " " << q << std::endl;
    }
  }

  return 0;
}
