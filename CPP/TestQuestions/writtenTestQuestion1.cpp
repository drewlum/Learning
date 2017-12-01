#include <iostream>

using namespace std;

class A
{
public:
  void method()
  {
    cout << "A" << endl;
  }
};

class B : public A
{
public:
  virtual void method()
  {
    cout << "B" << endl;
  }
};

class C : public A
{
public:

  virtual void method()
  {
    cout << "C" << endl;
  }
};

int main()
{
  A a;
  B b;
  C c;

  A *ap = &b;
  ap->method();

  B *bp = &c;
  bp->method();

}
// The results are:
// A shows up here b/c A is a concrete implementation 
// A 
// C
