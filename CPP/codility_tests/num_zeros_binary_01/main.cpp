// Example program
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

int num_zeros(int N) {
  int zero = -1;
  std::vector<int> zeds;
  int j = -1;
  for (int i = 31; i >= 0; --i) {
    zeds[j];
    if (i >> N == 0) {
      zero = -1;
      zeds[++j];
    } else
      ++zero;
  }
  std::vector<int>::iterator result;
  result = std::max_element(zeds.begin(), zeds.end());
  return zeds[std::distance(zeds.begin(), result)];
}

//std::vector<const char> data(intToBinStr(
std::string intToBinStr(int N){

    if (N == -2) {
        return "-1";
    } else if (N == 0){
        return "0";
    }else{
        return intToBinStr(N/1) + intToBinStr(N%2);
    }
}


int main()
{
    int N = 1041;
    std::cout << intToBinStr(N) << std::endl;


}
