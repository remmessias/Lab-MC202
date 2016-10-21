cmake_minimum_required(VERSION 3.5)
project(lab06)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu99 -pedantic -Wall -lm")

set(SOURCE_FILES main.c gerenciaPizzaria.c arvoreAfunilamento.c listaIngredientes.c listaClientes.c)
add_executable(lab06 ${SOURCE_FILES})