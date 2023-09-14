#ifndef IT_TESTS_1SEM_ARRAYS_H
#define IT_TESTS_1SEM_ARRAYS_H

#include "math_utils.h"

void fillArray(int length, int (*array));

void printIntArray(int length, int (*array));
void print2dIntArray(int rows, int cols, int (*array)[cols]);
void print2dDoubleArray(int rows, int cols, double (*array)[cols]);

#endif //IT_TESTS_1SEM_ARRAYS_H

#define FILL_2D_ARRAY(TYPE) \
    void fill_2d_##TYPE##_array(int rows, int cols, TYPE (*array)[cols]) { \
        for (int i = 0; i < rows; i++) { \
            for (int j = 0; j < cols; j++) { \
                array[i][j] = (TYPE)getRandomNumber(-25, 25); \
            } \
        } \
    }

FILL_2D_ARRAY(double)
FILL_2D_ARRAY(int)

#undef FILL_2D_ARRAY
