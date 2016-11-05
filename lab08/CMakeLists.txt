cmake_minimum_required(VERSION 3.5)
project(lab08)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -pedantic -Wall -lm")

set(SOURCE_FILES main.c main.c)
add_executable(lab08 ${SOURCE_FILES})