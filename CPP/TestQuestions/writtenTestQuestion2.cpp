#include <iostream>

using namespace std;


bool cont_1()
{ 
  //cout << "cont_1" << end;
  return true;
}

bool cont_2()
{
  //cout << "cont_2" << endl;
  return false;
}


int main()
{

  bool rv1 = cont_2() && cont_1();
  bool rv2 = cont_1() || cont_2();
  bool rv3 = false && true;
  bool rv4 = true || false;
  cout << rv1 << endl;
  cout << rv2 << endl;
  cout << rv3 << endl;
  cout << rv4 << endl;

  return 0;
}
