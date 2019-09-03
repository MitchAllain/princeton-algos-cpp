#include "abstract_uf.h"

template class std::unique_ptr<int[]>;

AbstractUF::AbstractUF(int n)
  : sz_{n},
    id_(sz_, 0)
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

void AbstractUF::writeGraph(std::ofstream& outfile)
{
  outfile << "// The graph name and the semicolons are optional" << std::endl <<
"graph {" << std::endl;

  for (int i = 0; i < sz_; i++)
  {
    outfile << i << " -- " << id_[i] << std::endl;
  }

  outfile << "}" << std::endl;
}
