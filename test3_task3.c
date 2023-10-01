#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "math_utils.h"
#include "arrays.h"
#include "menu.h"

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
 * @param sumFunc - function to fold array with
 * @return folded array
 */
int foldArray(int* arr, int size, int (*sumFunc)(int, int)) {
    int result = 0;

    for (int i = 0; i < size; i++) {
        result = sumFunc(result, arr[i]);
    }

    return result;
}

/**
 * Fills array with random numbers from -25 to 25,
 * then sums it up and prints it
 *
 * @param arrayLength - size of array
 */
void solveTask(int arrayLength) {
    int array[arrayLength];

    fillIntArray(arrayLength, array);
    printIntArray(arrayLength, array);

    int sumOfArray = foldArray(array, arrayLength, sum);
    printf("\nSum of array: %d\n", sumOfArray);
}

int main(void) {
    srand(time(NULL));
    getWelcomeMessage(getStudent(), 3, 3);

    int currentPickedOption = -1;

    while (currentPickedOption != 9)
    {
        printMenuOptions();
        currentPickedOption = getMenuOption();

        int arrayLength = 0;
        switch (currentPickedOption) {

            case 1: {
                int isArgValid = 0;

                printf("Input array length:");
                do {
                    if (scanf("%d", &arrayLength) == 1 && arrayLength > 1) {
                        printf("Valid input: %d\n", arrayLength);
                        isArgValid = 1;
                    }
                    else {
                        onInvalidInput("enter only int values from 2 to any");
                    }
                } while (isArgValid != 1);

                solveTask(arrayLength);
                break;
            }
            case 2: {
                arrayLength = (int) getRandomNumber(2, 10);

                printf("\nRandom array length: %d\n", arrayLength);

                solveTask(arrayLength);
                break;
            }
            case 3: {
                system("cls");
            }
            case 9: {
                puts("Exiting...");
                break;
            }
            case 0:
            default:{
                onInvalidInput("enter a valid option\n");
                break;
            }
        }
    }

    return EXIT_SUCCESS;
}
