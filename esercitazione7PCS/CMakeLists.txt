cmake_minimum_required(VERSION 3.10)
project(Esercitazione9_Grafi)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


add_executable(main_esercitazione 
    main.cpp 
    classi_Arco_grafo.h 
    grafi_visita.h
)