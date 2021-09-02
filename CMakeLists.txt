cmake_minimum_required(VERSION 3.20)
project(DataStructure)

set(CMAKE_CXX_STANDARD 14)

add_executable(DataStructure main.cpp)

add_executable(Sqlist_shunxubiao sqlist/Sqlist_shunxubiao.cpp)
add_executable(Sqlist_danlianbiao sqlist/Sqlist_danlianbiao.cpp)
add_executable(Sqlist_shuanglianbiao sqlist/Sqlist_shuanglianbiao.cpp)