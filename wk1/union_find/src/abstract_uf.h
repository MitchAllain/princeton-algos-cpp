#ifndef ABSTRACT_UF_H_
#define ABSTRACT_UF_H_

#include <memory>

class AbstractUF
{
public:
  AbstractUF(int n);
  // virtual int count() = 0;
  virtual int qfind(int p);
  virtual bool connected(int p, int q) = 0;
  virtual void connect(int p, int q) = 0;
protected:
  int sz_;
  std::unique_ptr<int[]> id_;
};

#endif  // ABSTRACT_UF_H_
