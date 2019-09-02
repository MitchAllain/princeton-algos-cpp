#include "quick_union_uf.h"

QuickUnionUF::QuickUnionUF(int n)
  : AbstractUF(n) {}

int QuickUnionUF::root(int p)
{
  int i = p;
  while (id_[i] != i) i = id_[i];
  return i;
}

void QuickUnionUF::connect(int p, int q)
{
  int pid = root(p);
  int qid = root(q);

  id_[pid] = qid;
}

bool QuickUnionUF::connected(int p, int q)
{
  return (root(p) == root(q));
}
