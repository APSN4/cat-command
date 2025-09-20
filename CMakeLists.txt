cmake_minimum_required(VERSION 3.30)
project(cat_command C)

set(CMAKE_C_STANDARD 11)

add_executable(cat_command main.c
        src/parser.h
        src/parser.c
        src/arguments.h
        src/arguments.c)
