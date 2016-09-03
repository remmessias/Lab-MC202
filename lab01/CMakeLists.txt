cmake_minimum_required(VERSION 3.5)
project(lab01)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -pedantic -Wall -lm")

set(SOURCE_FILES main.c)
add_executable(lab01 ${SOURCE_FILES})