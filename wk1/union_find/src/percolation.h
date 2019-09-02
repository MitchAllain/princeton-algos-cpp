##ifndef PERCOLATION_H_
#define PERCOLATION_H_

class Percolation {
public:
  Percolation(int n);
  void open(int row, int col);
  bool isOpen(int row, int col);
  bool isFull(int row, int col);
  int numberOfOpenSites();
  bool percolates();
}

#endif  // PERCOLATION_H_
