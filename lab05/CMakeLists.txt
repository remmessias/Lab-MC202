cmake_minimum_required(VERSION 3.5)
project(lab05)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -pedantic -Wall -lm")

set(SOURCE_FILES main.c arvore.c gerenciaArquivos.c)
add_executable(lab05 ${SOURCE_FILES})