#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdint>

typedef std::map<std::string, std::vector<uint32_t>> MapT;
typedef std::map<std::pair<std::string, uint32_t>, std::vector<std::string> > BufferMapT;

bool isGwKeyPresent(BufferMapT& theMap, std::string theKey)
{
  bool isTrue = false;
  for(const auto& pair : theMap)
  {
    if(pair.first.first == theKey)
    {
      isTrue = true;
      return isTrue;
    }
  }
  return isTrue;
}

uint32_t findSeqNumGap(std::vector<uint32_t>& theVec)
{
  uint32_t next = theVec[theVec.size()-1];
  for(int i=theVec.size()-1; i!=0;i--)
  {
    if(theVec[i] !=next)
      return next;
    --next;
  }
  return 0;
}

uint32_t findSeqNumGap(MapT& theMap, const std::string& gwkey)
{
  uint32_t next = theMap[gwkey][theMap[gwkey].size()-1];
  for(int i=theMap[gwkey].size()-1; i!=0;i--)
  {
    if(theMap[gwkey][i] !=next)
      return next;
    --next;
  }
  return 0;
}

std::vector<uint32_t> findAllSeqNumGaps(MapT& theMap, const std::string& gwkey)
{
  std::vector<uint32_t> myVec;
  uint32_t next = theMap[gwkey][theMap[gwkey].size()-1];
  for(int i=theMap[gwkey].size()-1; i!=0;i--)
  {
    if(theMap[gwkey][i] !=next)
    {
      std::cout << "next: " << i << std::endl;
      myVec.push_back(next);
    }
    --next;
  }
  myVec.push_back(next); 
  std::sort(myVec.begin(), myVec.end());
  return myVec;
}

void sortMappedVector(MapT& theMap, std::string gwkey)
{
  std::sort(theMap[gwkey].begin(),theMap[gwkey].end());
}
  
std::vector<uint32_t> getMapSeqNumGap(BufferMapT& theMap, std::string gwKey)
{
  std::vector<uint32_t> vec;
  for(const auto& i : theMap)
  {
    if(i.first.first == gwKey)
    {
      std::cout << i.first.second << std::endl;
    }
    vec.push_back(i.first.second);
  }
  return vec;
}

int main ()
{
  BufferMapT bufMap;
  bufMap[std::make_pair("vp1",1)].emplace_back(std::string("blah1"));
  bufMap[std::make_pair("vp1",11)].emplace_back(std::string("blah11"));
  bufMap[std::make_pair("vp1",14)].emplace_back(std::string("blah14"));
  bufMap[std::make_pair("vp1",10)].emplace_back(std::string("blah10"));
  bufMap[std::make_pair("vp1",11)].emplace_back(std::string("blah11"));
  bufMap[std::make_pair("vp1",12)].emplace_back(std::string("blah12"));
  bufMap[std::make_pair("up1",24)].emplace_back(std::string("blah24"));
  bufMap[std::make_pair("up2",25)].emplace_back(std::string("blah24"));

  MapT myMap;
  myMap["vp3"].push_back(11);
  myMap["vp3"].push_back(12);
  myMap["vp1"].push_back(11);
  myMap["vp1"].push_back(12);
  myMap["vp1"].push_back(14);
  myMap["vp1"].push_back(8);
  myMap["vp1"].push_back(9);
  myMap["vp1"].push_back(11);
  myMap["vp1"].push_back(10);
  myMap["vp1"].push_back(5);
  myMap["vp1"].push_back(7);


  sortMappedVector(myMap, std::string("vp1"));

  for( const auto& pair : myMap)
  {
    std::cout << "key: " << pair.first << " value: [ ";
    for( int i=0; i< pair.second.size(); ++i)
    {
      std::cout << pair.second[i] << " ] \n";
    }
  }
  
  int32_t gap = findSeqNumGap(myMap,std::string("vp1"));
  std::cout << "seq num gap: " << gap << std::endl;
  std::pair<std::string, uint32_t> bufKey = std::make_pair("vp1", gap);
  bufMap[bufKey].emplace_back(std::string("blah" + std::to_string(gap)));
  //std::cout << bufMap[bufKey][0].c_str() << std::endl;
  //std::cout << bufMap[bufKey].size() << std::endl;
  //std::cout << "missing seq number " << findGap(myMap, std::string("vp1")) << std::endl;
//  for( BufferMapT::iterator it = bufMap.begin(); it !=bufMap.end(); ++it )
//  {
//    std::cout << "first: " << it->first.first << " second: " << it->first.second << std::endl; 
//  }

  for( auto& pair : bufMap )
  {
    std::cout << "first: " << pair.first.first << " second: " << pair.first.second << std::endl;
  }
  
  std::cout << "is key in bufferMap: " << isGwKeyPresent(bufMap,std::string("vp1")) << std::endl;
  std::cout << "is key in bufferMap: " << isGwKeyPresent(bufMap,std::string("cp1")) << std::endl;

  std::cout << "all the missing keys: ";

  std::vector<uint32_t> vec = findAllSeqNumGaps(myMap,std::string("vp1"));

  for(const auto& i : vec)
  {
     std::cout << "missing: " << i << std::endl;
  }
  getMapSeqNumGap(bufMap, std::string("vp1"));  
  return 0;
}
