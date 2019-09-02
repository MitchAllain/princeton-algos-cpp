#include "quick_find_uf.h"

QuickFindUF::QuickFindUF(int n)
  : AbstractUF(n) {}

bool QuickFindUF::connected(int p, int q)
{
  return (id_[p] == id_[q]);
}

void QuickFindUF::connect(int p, int q)
{
  int pid = id_[p];
  int qid = id_[q];

  for (int i = 0; i < sz_; i++)
  {
    if (id_[i] == pid) id_[i] = qid;
  }
}
