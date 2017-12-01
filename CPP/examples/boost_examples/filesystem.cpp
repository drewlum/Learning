//g++ main.cpp --std=c++11 -static -L/opt/lib/ -lboost_filesystem -lboost_system -I /opt/include/

//This example comes from:
//http://stackoverflow.com/questions/4283546/cboostfilesystem-how-can-i-get-a-list-of-files-in-a-folder-in-which-the-fi

#include <boost/filesystem.hpp>

#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>

namespace fs=boost::filesystem;

int main(int argc,char*argv[]) {

  fs::path directoryName("/opt/include/boost");
  fs::directory_iterator                          end_iter;
  std::vector<fs::directory_entry                 fileVector;
  std::vector<std::string>                        fileList;
  typedef std::multimap<time_t, fs::path>         fs_map;
  fs_map                                          myFsMap;

  try
  {
    if( fs::exists(directoryName) && fs::is_directory(directoryName) )
    {
      for( fs::directory_iterator it(directoryName); it!=end_iter; ++it )
      {
        if( fs::is_regular_file(it->status()))
        {
          myFsMap.insert(fs_map::value_type(fs::last_write_time(*it),*it));
        }
      }
    }else
    {
      std::cerr << directoryName <<"Either doesn't exist or is a file and not a directory" << std::endl;
    }
  }
  catch(const fs::filesystem_error &ex)
  {
    std::cerr << ex.what() << std::endl;
  }

 for ( fs_map::iterator it=myFsMap.begin(); it !=myFsMap.end();++it)
 {
   fileList.push_back((*it).second.string());
 }

 for ( std::vector<std::string>::iterator it=fileList.begin(); it !=fileList.end(); ++it){
   std::cout << *it << std::endl;
 }

  return 0;
}
