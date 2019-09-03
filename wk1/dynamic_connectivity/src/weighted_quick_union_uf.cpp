#include "weighted_quick_union_uf.h"

WeightedQuickUnionUF::WeightedQuickUnionUF(int n)
  : AbstractUF(n),
    card_(n, 1) {}

int WeightedQuickUnionUF::root(int p)
{
  int i = p;
  while (id_[i] != i) i = id_[i];
  return i;
}

int WeightedQuickUnionUF::qfind(int p)
{
  return root(p);
}

void WeightedQuickUnionUF::connect(int p, int q)
{
  int pid = root(p);
  int qid = root(q);
  if (pid == qid) return;

  if (card_[pid] > card_[qid])
  {
    id_[qid] = pid;
    card_[pid] += card_[qid];
  }
  else
  {
    id_[pid] = qid;
    card_[qid] += card_[pid];
  }
}

bool WeightedQuickUnionUF::connected(int p, int q)
{
  return (root(p) == root(q));
}
