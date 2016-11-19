cmake_minimum_required(VERSION 3.5)
project(lab09)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -pedantic -Wall -lm")

set(SOURCE_FILES exemplo.c)
add_executable(lab09 ${SOURCE_FILES})