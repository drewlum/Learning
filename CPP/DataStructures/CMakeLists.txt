cmake_minimum_required(VERSION 2.8)

project(RelerningCPP)

if(CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "-std=c++Ox -Wall")
endif()
add_subdirectory(LinkedList)
