cmake_minimum_required(VERSION 3.20)
project(DataStructure)

set(CMAKE_CXX_STANDARD 14)

add_executable(main main.cpp)

add_executable(Sqlist_shunxubiao sqlist/Sqlist_shunxubiao.cpp)
add_executable(Sqlist_danlianbiao sqlist/Sqlist_danlianbiao.cpp)
add_executable(Sqlist_shuanglianbiao sqlist/Sqlist_shuanglianbiao.cpp)
add_executable(stack_shunxuzhan stack/stack_shunxuzhan.cpp)
add_executable(stack_lianzhan stack/stack_lianzhan.cpp)
add_executable(queue_shunxudui queue/queue_shunxudui.cpp)
add_executable(queue_liandui queue/queue_liandui.cpp)
add_executable(tree tree/tree.cpp)