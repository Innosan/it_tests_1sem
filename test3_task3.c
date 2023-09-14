#include <stdio.h>
#include <stdlib.h>
#include "math_utils.h"
#include "arrays.h"

int sum(int a, int b) {
    return a + b;
}

int fold(int* arr, int size, int (*sumFunc)(int, int)) {
    int result = 0;

    for (int i = 0; i < size; i++) {
        result = sumFunc(result, arr[i]);
    }

    return result;
}

int main(void) {
    getWelcomeMessage(getStudent(), 3, 3);

    int arrayLength = 0;
    int isArgValid = 0;

    printf("Input array length:");
    do {
        if (scanf("%d", &arrayLength) == 1 && arrayLength > 0) {
            printf("Valid input: %d\n", arrayLength);
            isArgValid = 1;
        }
        else {
            printf("Invalid input. Please enter only int values from 1 to any.\n");
            while (getchar() != '\n');
        }
    } while (isArgValid != 1);

    int array[arrayLength];

    fillArray(arrayLength, array);
    printIntArray(arrayLength, array);

    int sumOfArray = fold(array, arrayLength, sum);
    printf("\nSum of array: %d\n", sumOfArray);

    return EXIT_SUCCESS;
}
