#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "math_utils.h"
#include "arrays.h"
#include "inputs.h"
#include "memory.h"
#include "menu.h"

#define MINIMUM_ARRAY_SIZE 2

/**
 * Sums two numbers
 * @param a - sum being added
 * @param b - number to add
 * @return sum of two numbers
 */
int sum(int a, int b) {
    return a + b;
}

/**
 * Folds array with sum function
 * @param arr - array to fold
 * @param size - size of array
 * @param foldWith - function to fold array with
 * @return sum of elements in array
 */
int foldArray(int *arr, int size, int (*foldWith)(int, int)) {
    int result = 0;

    for (int i = 0; i < size; i++) {
        result = foldWith(result, arr[i]);
    }

    return result;
}

/**
 * Fills array with random numbers from -25 to 25,
 * then sums it up and prints it
 *
 * @param arrayLength - size of array
 */
void solveTask(int arrayLength, int *array) {
    printDynamicIntArray(arrayLength, array);

    int sumOfArray = foldArray(array, arrayLength, sum);
    printf("\nSum of array: %d\n", sumOfArray);
}

int main(void) {
    srand(time(NULL));
    getWelcomeMessage(getStudent(), 3, 3);

    int currentPickedOption = -1;

    while (currentPickedOption != EXIT)
    {
        printMenuOptions();
        currentPickedOption = getMenuOption();

        int arrayLength = MINIMUM_ARRAY_SIZE;
        switch (currentPickedOption) {

            case MANUAL_INPUT: {
                while (arrayLength <= MINIMUM_ARRAY_SIZE) {
                    printf("Input array length:");
                    arrayLength = getIntInput();

                    if (arrayLength <= MINIMUM_ARRAY_SIZE) {
                        printf("Degree should be more than %d!", MINIMUM_ARRAY_SIZE);
                    }
                }

                int *array = allocateArray(arrayLength);
                manualFillIntArray(arrayLength, array);

                solveTask(arrayLength, array);

                freeArray(array);
                break;
            }
            case RANDOM_INPUT: {
                arrayLength = (int) getRandomNumber(2, 10);
                printf("\nRandom array length: %d\n", arrayLength);

                int *array = allocateArray(arrayLength);
                fillDynamicIntArray(arrayLength, array);

                solveTask(arrayLength, array);

                freeArray(array);
                break;
            }
            case EXIT: {
                puts("Exiting...");
                break;
            }
            default:{
                onInvalidInput("enter a valid option\n");
                break;
            }
        }
    }

    return EXIT_SUCCESS;
}
