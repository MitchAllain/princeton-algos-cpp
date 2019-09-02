#ifndef QUICK_UNION_H_
#define QUICK_UNION_H_

#include "abstract_uf.h"

class QuickUnionUF : public AbstractUF
{
public:
  QuickUnionUF(int n);
  int qfind(int p);
  bool connected(int p, int q);
  void connect(int p, int q);
private:
  int root(int p);
};

#endif  // QUICK_UNION_H_
