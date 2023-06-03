cmake_minimum_required(VERSION 3.25.1)
# 项目名称
project(Data-structure VERSION 0.1.0 LANGUAGES C CXX)

# 指定语言标准
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)

# 对Debug不使用优化
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -O0")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")

# 对release使用O2优化
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O2")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")

# 设置输出目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_subdirectory(src/LinearList)
