#include "percolation.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include <memory>

#include "quick_find_uf.h"
#include "quick_union_uf.h"
#include "weighted_quick_union_uf.h"

Percolation::Percolation(int n, char* strategy)
  : n_(n),
    grid_sz_(n * n),
    i_top_(grid_sz_),
    i_bottom_(grid_sz_ + 1),
    open_(grid_sz_, false)
{
  uf_ = read_strategy(strategy);
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

std::unique_ptr<AbstractUF> Percolation::read_strategy(char* arg)
{
  if (strcmp(arg, "qu") == 0)
  {
    // std::cout << "QuickUnionUF" << std::endl;
    return std::unique_ptr<AbstractUF>{new QuickUnionUF(grid_sz_ + 2)};
  }
  else if (strcmp(arg, "qf") == 0)
  {
    // std::cout << "QuickFindUF" << std::endl;
    return std::unique_ptr<AbstractUF>{new QuickFindUF(grid_sz_ + 2)};
  }
  else
  {
    // std::cout << "WeightedQuickUnionUF" << std::endl;
    return std::unique_ptr<AbstractUF>{new WeightedQuickUnionUF(grid_sz_ + 2)};
  }
}

void Percolation::writeGraph()
{
  std::ofstream outfile("graph.gv");
  uf_->writeGraph(outfile);
}
