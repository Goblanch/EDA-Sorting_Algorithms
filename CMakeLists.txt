cmake_minimum_required(VERSION 3.26)
project(SortingAlgorithms)

set(CMAKE_CXX_STANDARD 17)

# 1) Librería con utilidades comunes
add_library(Common
        Common/VectorUtils.cpp
)

target_include_directories(Common PUBLIC
        Common
)

# 2) Ejecutable BubbleSort
add_executable(BubbleSort
        BubbleSort/main.cpp
)
target_link_libraries(BubbleSort PRIVATE Common)

# 3) Ejecutable BubbleSortMejorado
add_executable(BubbleSortMejorado
        OptimizedBubbleSort/main.cpp
)
target_link_libraries(BubbleSortMejorado PRIVATE Common)
