cmake_minimum_required(VERSION 3.26)
project(it_tests_1sem C)

set(CMAKE_C_STANDARD 17)

include_directories(.)

add_executable(it_tests_1sem
        math_utils.c
        math_utils.h
        task_structures.h
        test2_task3.c
)
