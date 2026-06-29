cmake_minimum_required(VERSION 3.12)
project(UltimaEsercitazioneGrafi VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(grafi_lib INTERFACE)

target_sources(grafi_lib INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/classiArcoGrafoConSet.h
    ${CMAKE_CURRENT_SOURCE_DIR}/DePina.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Dijkstra.h
    ${CMAKE_CURRENT_SOURCE_DIR}/grafi_visita.h
)

# Compila l'eseguibile usando test.cpp al posto di main.cpp
add_executable(main test.cpp)
target_link_libraries(main PRIVATE grafi_lib)