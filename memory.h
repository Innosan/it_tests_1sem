#ifndef IT_TESTS_1SEM_MEMORY_H
#define IT_TESTS_1SEM_MEMORY_H

/**
 * Allocates memory for a 2D array.
 *
 * @param rows - The number of rows in the 2D array.
 * @param cols - The number of columns in the 2D array.
 * @return - A pointer to the 2D array.
 */
double** allocate2dArray(int rows, int cols);

/**
 * Allocates memory for an array.
 *
 * @param length - The length of the array.
 * @return - A pointer to the array.
 */
int* allocateArray(int length);

/**
 * Frees the memory allocated for a 2D array.
 *
 * @param rows - The number of rows in the 2D array.
 * @param array - The 2D array to be freed.
 */
void free2dArray(int rows, double **array);

/**
 * Frees the memory allocated for a 2D array.
 *
 * @param length - The length of the array.
 * @param array - The array to be freed.
 */
void freeArray(int *array);

#endif //IT_TESTS_1SEM_MEMORY_H
