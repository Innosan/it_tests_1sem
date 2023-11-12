cmake_minimum_required(VERSION 3.26)
project(it_tests_1sem C)

set(CMAKE_C_STANDARD 17)

include_directories(.)

add_executable(it_tests_1sem
        #headers
        arrays.h
        math_utils.h
        task_structures.h
        menu.h
        inputs.h

        #modules
        math_utils.c
        arrays.c
        menu.c
        inputs.c

        #programs
#        test1_task1.c
#        test1_task2.c
#        test1_task3.c
#        test2_task1.c
#        test2_task2.c
        test2_task3.c
#        test3_task1.c
#        test3_task2.c
#        test3_task3.c

#        lectureTask.c
)
