#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdint>

typedef std::map<std::string, std::vector<uint32_t>> MapT;
typedef std::pair<std::string, uint32_t>  BufferKeyT;
typedef std::map<BufferKeyT, std::vector<std::string>> BufferMapT;

class MyMapClass
{
public:
  MyMapClass()
  {
    //gwKeysMap.insert(std::pair<std::string, std::vector<uint32_t>>(std::string(), std::vector<uint32_t>()));
  }
  
  void run()
  {
    std::cout << "gwKeysMap.size(): " << gwKeysMap.size() << std::endl;
    std::cout << "gwKeysMap.empty(): " << gwKeysMap.size() << std::endl;
  }
private: 
  MapT gwKeysMap;
  BufferMapT bufMap;
};

int main()
{
  MyMapClass mmc;
  mmc.run();
}
