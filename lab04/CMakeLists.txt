cmake_minimum_required(VERSION 3.5)
project(lab04)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -pedantic -Wall -lm")

set(SOURCE_FILES main.c sudokuDasRainhas.c pilha.c)
add_executable(lab04 ${SOURCE_FILES})