#include "percolation.h"

#include <iostream>

#include "quick_find_uf.h"
#include "quick_union_uf.h"
#include "weighted_quick_union_uf.h"

Percolation::Percolation(int n)
  : n_(n),
    grid_sz_(n * n),
    i_top_(grid_sz_),
    i_bottom_(grid_sz_ + 1),
    uf_{new WeightedQuickUnionUF(grid_sz_ + 2)},
    open_(grid_sz_, false)
{
  // std::cout << "New Percolation instance with " << grid_sz_ << " sites." << std::endl;
  // std::fill(*open_, *open_ + grid_sz_, false);
}


void Percolation::open(int row, int col)
{
  int i = index(row, col);
  if (open_[i]) {return;}

  connectAbove(row, col);
  connectBelow(row, col);
  connectLeft(row, col);
  connectRight(row, col);

  open_[i] = true;
  return;
}

void Percolation::connectAbove(int row, int col)
{
  int i = index(row, col);

  if (row == 0)
  {
    uf_->connect(i, i_top_);
  }
  else if (isOpen(row - 1, col))
  {
    int j = index(row - 1, col);
    uf_->connect(i, j);
  }
}

void Percolation::connectBelow(int row, int col)
{
  int i = index(row, col);

  if (row == n_ - 1)
  {
    uf_->connect(i, i_bottom_);
  }
  else if (isOpen(row + 1, col))
  {
    int j = index(row + 1, col);
    uf_->connect(i, j);
  }
}

void Percolation::connectLeft(int row, int col)
{
  int i = index(row, col);
  if ((col != 0) && isOpen(row, col - 1))
  {
    int j = index(row, col - 1);
    uf_->connect(i, j);
  }
}

void Percolation::connectRight(int row, int col)
{
  int i = index(row, col);
  if ((col != n_) && isOpen(row, col + 1))
  {
    int j = index(row, col + 1);
    uf_->connect(i, j);
  }
}

bool Percolation::isOpen(int row, int col)
{
  int i = index(row, col);
  return open_[i];
}

bool Percolation::isFull(int row, int col)
{
  return !isOpen(row, col);
}

int Percolation::numberOfOpenSites()
{
  int count = 0;
  for (int i = 0; i <= grid_sz_; i++)
  {
    if (open_[i]) {count++;}
  }
  return count;
}

bool Percolation::percolates()
{
  return uf_->connected(i_top_, i_bottom_);
}
