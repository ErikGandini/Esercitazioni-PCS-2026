cmake_minimum_required(VERSION 3.20)
project(esercitazione4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

add_executable(measure_sorts measure_sort.cpp timecounter.cpp)

enable_testing()



add_executable(test_bubble prova100vec_bubble.cpp)
add_test(NAME BubbleSortTest COMMAND test_bubble)


add_executable(test_insertion prova100vec_insertion.cpp)
add_test(NAME InsertionSortTest COMMAND test_insertion)


add_executable(test_selection prova100vec_selection.cpp)
add_test(NAME SelectionSortTest COMMAND test_selection)