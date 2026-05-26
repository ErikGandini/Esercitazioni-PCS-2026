cmake_minimum_required(VERSION 3.10)
project(GradienteConiugato CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Eigen3 REQUIRED)

add_executable(eseguibile_gc main.cpp)
target_link_libraries(eseguibile_gc PRIVATE Eigen3::Eigen)