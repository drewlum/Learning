#include <array>
#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

static int timesSwapped = 0;

void swap( int *lhs, int* rhs)
{
  int tmp = *lhs;
  *lhs = *rhs;
  *rhs = tmp;
}

void selectSort(vector<int>& vec)
{
  for(int i=0;i<vec.size();i++)
  {
    int min_index = i;
    for(int j=i+1;j < vec.size(); j++)
    {
      if(vec[j] < vec[min_index])
      {
        min_index = j;
      }
    }
    swap(&vec[min_index], &vec[i]);
    cout << "swapped times: " << ++timesSwapped << endl;
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
  selectSort(vec);
  printVector(vec);
}
