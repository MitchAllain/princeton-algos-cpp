#include "abstract_uf.h"

AbstractUF::AbstractUF(int n)
  : sz_{n},
    id_{new int[sz_]}
{
  for (int i = 0; i < sz_; i++)
  {
    id_[i] = i;
  }
}

// todo: curious about speed difference if this is inlined
int AbstractUF::qfind(int p)
{
  return id_[p];
}
