cmake_minimum_required(VERSION 3.20)
project(esercizio_media_temp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(SOURCES esercizo1.0.cpp)

add_executable(esercizio_media_temp ${SOURCES})