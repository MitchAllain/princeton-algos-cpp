#ifndef ABSTRACT_UF_H_
#define ABSTRACT_UF_H_

#include <memory>
#include <vector>
#include <fstream>

class AbstractUF
{
public:
  AbstractUF(int n);
  // virtual int count() = 0;
  virtual int qfind(int p);
  virtual bool connected(int p, int q) = 0;
  virtual void connect(int p, int q) = 0;
  virtual void writeGraph(std::ofstream& outfile);
  int getParent(int p) {return id_[p];}
protected:
  int sz_;
  std::vector<int> id_;
};

#endif  // ABSTRACT_UF_H_
