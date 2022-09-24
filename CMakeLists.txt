cmake_minimum_required(VERSION 3.16)
project(atcoder_workspace)

set(CMAKE_CXX_STANDARD 17)

add_executable(atcoder_workspace abc269/E/main.cpp)
#add_executable(atcoder_workspace arc144/B/main.cpp)
include_directories(../../atcoder/ac-library/)