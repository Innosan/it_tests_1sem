#include <stdio.h>
#include "arrays.h"
#include "math_utils.h"

void fillArray(int length, int (*array)) {
    for (int i = 0; i < length; i++) {
        array[i] = (int)getRandomNumber(-25, 25);
    }
}

/*
 * Printing arrays
 */

void printIntArray(int length, int (*array)) {
    printf("Array of %d length:\n", length);

    for (int i = 0; i < length; i++) {
        printf("%d, ", array[i]);
    }
}

void print2dIntArray(int rows, int cols, int (*array)[cols]) {
    printf("Matrix %d x %d:\n", rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%6d", array[i][j]);
        }

        puts("");
    }
}

void print2dDoubleArray(int rows, int cols, double (*array)[cols]) {
    printf("Matrix %d x %d:\n\n", rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%6.2f\t", array[i][j]);
        }

        puts("");
    }
}
