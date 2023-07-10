cmake_minimum_required (VERSION 3.16)
project (myproj VERSION 1.0)

find_package (glog 0.6.0 REQUIRED)

add_executable (myapp main.cpp)
##myapp依赖 glog库
target_link_libraries (myapp glog::glog)
