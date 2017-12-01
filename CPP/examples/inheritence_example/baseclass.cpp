/*
 * example from http://www.geeksforgeeks.org/virtual-destructor/
 * 9/27/2017
 */

#include<iostream>
 
using namespace std;
 
class base {
  public:
    base()     
    { cout<<"Constructing base \n"; }
    virtual ~base()
    { cout<<"Destructing base \n"; }     
};
 
class derived: public base {
  public:
    derived()     
    { cout<<"Constructing derived \n"; }
    ~derived()
    { cout<<"Destructing derived \n"; }
};
 
int main(void)
{
  derived *d = new derived();  
  //base *b = d;
  //delete b;
  delete d;
  //getchar();
  return 0;
}
