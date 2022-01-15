cmake_minimum_required(VERSION 3.18)
project(c C)

set(CMAKE_C_STANDARD 99)

add_executable(c main.c stack/tack.h list/list.h list/node.h)
