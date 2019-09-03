#ifndef QUICK_FIND_UF_H_
#define QUICK_FIND_UF_H_

#include "abstract_uf.h"

class QuickFindUF : public AbstractUF
{
public:
  QuickFindUF(int n);
  int count();
  bool connected(int p, int q);
  void connect(int p, int q);
};

#endif  // QUICK_FIND_UF_H_
