cmake_minimum_required(VERSION 3.5)
project(lab07)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -pedantic -Wall -lm")

set(SOURCE_FILES main.c gerenciaCache.c fila.c filaPrioridade.c)
add_executable(lab07 ${SOURCE_FILES})