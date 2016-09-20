cmake_minimum_required(VERSION 3.5)
project(lab03)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -pedantic -Wall -lm")

set(SOURCE_FILES main.c pilha.c auxiliar.c)
add_executable(lab03 ${SOURCE_FILES})