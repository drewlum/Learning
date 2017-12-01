#include <iostream>
#include <vector>

using namespace std;

double getVWAP(vector<pair<double,int>>& vec)
{
  double pProd = 0;
  int vSum = 0;
  
  for(auto& i : vec)
  {
    pProd += i.first * i.second;
    vSum += i.second;
  }
  
  double vwap = pProd / vSum;
  return vwap;
     
}

int main()
{
   vector<pair<double,int>> vec;
   vec.push_back(make_pair(100.0,5));
   vec.push_back(make_pair(120.0,10));
   vec.push_back(make_pair(20.5,15));

   double rv = getVWAP(vec);
   cout << rv << endl;
}
