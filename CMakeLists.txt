cmake_minimum_required(VERSION 3.26)
project(SortingAlgorithms)

set(CMAKE_CXX_STANDARD 17)

add_executable(BubbleSort
        BubbleSort/main.cpp
        Common/VectorUtils.cpp
)