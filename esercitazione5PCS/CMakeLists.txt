cmake_minimum_required(VERSION 3.20)
project(esercitazione5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

enable_testing()

add_executable(misura_medie misura_medie_vettori_dimN.cpp timecounter.cpp)
add_executable(tabella measure_sort.cpp timecounter.cpp)

add_executable(test_bubblesort selection_test100.cpp)
add_test(NAME bubblesort COMMAND test_bubblesort)

add_executable(test_insertionsort insertion_test100.cpp)
add_test(NAME insertionsort COMMAND test_insertionsort)

add_executable(test_selectionsort selection_test100.cpp)
add_test(NAME selectionsort COMMAND test_selectionsort)

add_executable(test_mergesort merge_sort_test100.cpp)
add_test(NAME mergesort COMMAND test_mergesort)

add_executable(test_quicksort quick_sort_test100.cpp)
add_test(NAME quicksort COMMAND test_quicksort)

add_executable(test_quickhybrid quick_sort_hybrid_test100.cpp)
add_test(NAME quickhybrid COMMAND test_quickhybrid)