#ifndef WEIGHTED_QUICK_UNION_H_
#define WEIGHTED_QUICK_UNION_H_

#include <vector>

#include "abstract_uf.h"

class WeightedQuickUnionUF : public AbstractUF
{
public:
  WeightedQuickUnionUF(int n);
  int qfind(int p);
  bool connected(int p, int q);
  void connect(int p, int q);
private:
  int root(int p);
  std::vector<int> card_;  // cardinality of the connected set
};

#endif  // WEIGHTED_QUICK_UNION_H_
