#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>

#include "percolation.h"


// https://stackoverflow.com/questions/2797813/how-to-convert-a-command-line-argument-to-int
int parseArg(char* argv)
{
  std::string arg = argv;

  try
  {
    std::size_t pos;
    int x = std::stoi(arg, &pos);
    if (pos < arg.size())
    {
      std::cerr << "Trailing characters after number: " << arg << '\n';
    }
    return x;
  }
  catch (std::invalid_argument const &ex)
  {
    std::cerr << "Invalid number: " << arg << '\n';
    throw;
  }
  catch (std::out_of_range const &ex)
  {
    std::cerr << "Number out of range: " << arg << '\n';
    throw;
  }
}

int main(int argc, char *argv[])
{
  int n = parseArg(argv[1]);
  int sz = n * n;

  int T = parseArg(argv[2]);

  Percolation perc(n);

  while (!perc.percolates())
  {
    int i = std::rand() % n;
    int j = std::rand() % n;
    // std::cout << perc.numberOfOpenSites() << " open sites / "
    //   << sz << " total cells." << std::endl;

    perc.open(i, j);
  }

  double p_est = (float)perc.numberOfOpenSites() / sz;
  printf("%i open sites of %i total cells.\n", perc.numberOfOpenSites(), sz);
  printf("p* is %.4f\n", p_est);
}
