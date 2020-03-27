cmake_minimum_required(VERSION 3.10)

# set the project name
project(DataStructuresAndAlgorithm VERSION 1.0)
# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)
add_subdirectory(Vector)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Vector)
add_executable(Test  ${DIR_SRCS})
# 添加链接库
target_link_libraries(Test Vector)