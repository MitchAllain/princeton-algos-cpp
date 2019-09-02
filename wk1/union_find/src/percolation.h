#ifndef PERCOLATION_H_
#define PERCOLATION_H_

#include <memory>
#include <vector>

#include "abstract_uf.h"

class Percolation {
public:
  Percolation(int n);
  int index(int row, int col) {return row * n_ + col;}
  void open(int row, int col);
  bool isOpen(int row, int col);
  bool isFull(int row, int col);
  int numberOfOpenSites();
  bool percolates();
private:
  int n_, grid_sz_, i_top_, i_bottom_;
  std::unique_ptr<AbstractUF> uf_;
  std::vector<bool> open_;
  void connectAbove(int row, int col);
  void connectBelow(int row, int col);
  void connectLeft(int row, int col);
  void connectRight(int row, int col);
};

#endif  // PERCOLATION_H_
