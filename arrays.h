#ifndef IT_TESTS_1SEM_ARRAYS_H
#define IT_TESTS_1SEM_ARRAYS_H

void fillIntArray(int length, int (*array));
void fillDoubleArray(int length, double (*array));
void fill2dIntArray(int rows, int cols, int (*array)[cols]);
void fill2dDoubleArray(int rows, int cols, double (*array)[cols]);

void printIntArray(int length, int (*array));
void printDoubleArray(int length, double (*array));
void print2dIntArray(int rows, int cols, int (*array)[cols]);
void print2dDoubleArray(int rows, int cols, double (*array)[cols]);

#endif //IT_TESTS_1SEM_ARRAYS_H
