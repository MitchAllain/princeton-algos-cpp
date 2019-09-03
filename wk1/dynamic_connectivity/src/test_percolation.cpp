#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <thread>

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
  if (argc < 3)
  {
    std::cerr << "Too few arguments. Only " << argc - 1 << " of 2 " << std::endl;
    return 1;
  }

  srand(time(NULL));

  int n = parseArg(argv[1]);
  int sz = n * n;

  Percolation perc(n, argv[2]);

  while (!perc.percolates())
  {
    int i = std::rand() % n;
    int j = std::rand() % n;

    perc.open(i, j);

    // perc.writeGraph();
    // uncomment below to watch graph updates
    // std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  double p_est = (float)perc.numberOfOpenSites() / sz;
  printf("%i open sites of %i total cells.\n", perc.numberOfOpenSites(), sz);
  printf("p* is %.4f\n", p_est);

}
