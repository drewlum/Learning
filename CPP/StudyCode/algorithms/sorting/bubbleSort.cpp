#include <array>
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

static int timesSwapped = 0;

void swap(int *lhs, int *rhs)
{
  int tmp = *lhs;
  *lhs = *rhs;
  *rhs = tmp;
}

int bubbleSort(vector<int>& vec)
{
  bool swapped = false;
  
  for(int i=0; i<vec.size(); i++)
  { 
    swapped = false;

    for(int j=0; j<vec.size() - 1;j++)
    {
      if(vec[j] > vec[j+1])
      {
        swap(&vec[j],&vec[j+1]);
        swapped = true;
        cout << "swapped times: " << ++timesSwapped << endl;
      }
    }

    if( swapped == false )
      break;
  }
}

void printVector(vector<int>& vec)
{
  for(int i=0; i<vec.size(); i++)
  {
    cout << vec[i] << endl;
  }
}

int main()
{
  vector<int> vec = {14,20,1,5,3,6,7,15,11,12,16,18,13,19,2,4,8,9,10,17};
  bubbleSort(vec);
  printVector(vec);
}
