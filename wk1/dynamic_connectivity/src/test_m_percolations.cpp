#include <string>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <numeric>
#include <cmath>

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

void printStats(std::vector<double>& v, std::string units)
{
  double sum = std::accumulate(v.begin(), v.end(), 0.0);
  double mean = sum / v.size();

  double sq_sum = std::inner_product(v.begin(), v.end(), v.begin(), 0.0);
  double stdev = std::sqrt(sq_sum / v.size() - mean * mean);

  printf("Mean: %.6f %s, Stdev: %.6f %s\n", mean, units.c_str(), stdev, units.c_str());
}

int main(int argc, char *argv[])
{
  if (argc < 4)
  {
    std::cerr << "Too few arguments. Only " << argc - 1 << " of 3 " << std::endl;
    return 1;
  }

  srand(time(NULL));

  int n = parseArg(argv[1]);
  int sz = n * n;

  int T = parseArg(argv[2]);

  std::vector<double> times(T, 0);
  std::vector<double> thresholds(T, 0);
  std::vector<int> depths(T, 0);

  auto t1 = std::chrono::high_resolution_clock::now();
  auto ts = t1;

  for (int t = 0; t < T; t++)
  {
    Percolation perc(n, argv[3]);

    while (!perc.percolates())
    {
      int i = std::rand() % n;
      int j = std::rand() % n;
      perc.open(i, j);

      // beware do not use these with large T values
      // perc.writeGraph();
      // uncomment below to watch graph updates
      // std::this_thread::sleep_for(std::chrono::milliseconds(100));

    }

    double p_est = (float)perc.numberOfOpenSites() / sz;

    auto t2 = std::chrono::high_resolution_clock::now();
    auto dur_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
    times[t] = dur_ms.count();

    thresholds[t] = p_est;
    // perc.writeGraph();

    t1 = t2;
  }

  printf("\np*\n--\n");
  printStats(thresholds, "");

  printf("\nwall time\n---------\n");
  printStats(times, "ms");

  auto dur_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t1 - ts);
  printf("\nTotal simulation time %.3f ms\n", (double)dur_ms.count());
}
