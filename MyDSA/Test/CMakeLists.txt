cmake_minimum_required(VERSION 3.10)

# set the project name
project(DataStructuresAndAlgorithm VERSION 1.0)
# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/)
# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/math/)
option (USE_MYMATH
    "Use provided math implementation" ON)
# 是否加入 MathFunctions 库
if (USE_MYMATH)
    include_directories ("${PROJECT_SOURCE_DIR}/math")
    # 添加 math 子目录
    add_subdirectory(math) 
    set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)
# add the executable
# add_executable(Test main.cpp sayHello.cpp)
add_executable(Test ${DIR_SRCS})
# 添加链接库
target_link_libraries(Test MathFunctions)