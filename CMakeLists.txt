cmake_minimum_required(VERSION 2.5)
project(net_c-)
# net_c- 最终编译成so动态库，设置动态库的路径，放在根目录的lib文件夹下
set(LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib})
# 设置调试信息 启动C++ 11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_GLAGS} -g -std=c++11")
# 定义参与编译的原文件
aux_source_directory(. SRC_LIST)
# 编译成动态库 net_)c-
add_library(net_c- SHARED ${SRC_LIST})