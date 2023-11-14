#include <stdlib.h>
#include "memory.h"

double** allocate2dArray(int rows, int cols) {

    // Allocate memory for 'rows' number of pointers to double.
    // These pointers will each point to a 1D array.
    double **array = (double **)malloc(rows * sizeof(double *));

    // For each row, allocate memory for 'cols' number of double
    for (int i = 0; i < rows; i++) {
        array[i] = (double *)malloc(cols * sizeof(double));
    }

    // Return the pointer to the 2D array.
    return array;
}

int* allocateArray(int length) {
    int *array = (int*) malloc(length * sizeof(int));

    return array;
}

void free2dArray(int rows, double **array) {

    // For each row, free the memory allocated for the 1D array.
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }

    // Free the memory allocated for the pointers to the 1D arrays.
    free(array);
    array = NULL;
}

void freeArray(int *array) {
    // Free the memory allocated for the elements of the 1D array.
    free(array);
    array = NULL;
}

