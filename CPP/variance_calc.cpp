#include <iostream>
#include <vector>
using namespace std;


double mean(const vector<double>& thisVec)
{
  double rv = 0;
  for( auto i : thisVec )
  {
    rv += i;
  }
  return rv / thisVec.size();
}

//double variance(const vector<int>& myvec, double mean)  // this shoud have been vector<double>
double variance(const vector<double>& myvec, double mean)
{  
 //vector<int> sums; //this should have never been added
 //int theSum;  //should have been a double
 double theSum;
 for( int i=0; i<myvec.size(); i++ )  //this should have started at zero 
 { 
   //int res = myvec[i] - mean; //I should have clarified with you on the formula
   theSum += (myvec[i] - mean) * (myvec[i] - mean); 
   //sums.push_back(res*res); 
 } 
 /*
 for( auto& i : sums) 
 { 
   theSum = theSum + i; 
 } 
 */
  
  //return 1/myvec.size() * theSum; //return to the original issue with being clear with the problem
  return theSum / myvec.size();
}

/* original codepad code
double variance(const vector<int>& myvec, double mean)
{ 
  vector<int> sums;
  int theSum;
  for( int i=1; i<myvec.size(); i++ )
  {
    int res = myvec[i] - mean;
    sums.push_back(res*res);
  }
  
  for( auto& i : sums)
  {
    theSum = theSum + i;
  }
  
  return 1/myvec.size() * theSum;
}
*/

int main() {
  const vector<double> theVec = { 5.75, 10.5, 20.0, 800.0, 1001.25 };
  double theMean = mean(theVec);
  printf("the result is %f \n", variance(theVec, theMean));
  printf("the mean is: %f \n", mean(theVec));  
  return 0;
}

// variance: 1/N * ( sum ((x_i - x_mean)^2))

