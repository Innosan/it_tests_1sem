// system libs
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// dev libs
#include "arrays.h"
#include "math_utils.h"
#include "menu.h"
#include "inputs.h"

#define ARRAY_SIZE 25

void solveMath(double *array, int arrayLength) {
    int p = 0;

    double maxElem, minElem = array[0];
    int maxElemIndex, minElemIndex= 0;

    printDoubleArray(arrayLength, array);

    // finding max and min elements with their indexes
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (array[i] >= maxElem) {
            maxElem = array[i];
            maxElemIndex = i;
        }
        else if (array[i] <= minElem) {
            minElem = array[i];
            minElemIndex = i;
        }
    }

    // calculating value of p (divider) based on min and max index
    p = (minElemIndex + maxElemIndex) / 2;

    printf("\n\nMax elem: %.2f with position %d", maxElem, maxElemIndex + 1);
    printf("\nMin elem: %.2f with position %d", minElem, minElemIndex + 1);
    printf("\n\nP: %d", p + 1);

    puts("\n\nX sequence:");
    for (int i = 0; i <= p; ++i) {
        printf("%6.2f, ", array[i]);
    }

    puts("\nY sequence:");
    for (int i = p + 1; i < arrayLength; ++i) {
        printf("%6.2f, ", array[i]);
    }
}

int main(void) {
    srand(time(NULL));

    getWelcomeMessage(getStudent(), 2, 2);
    int currentPickedOption = -1;

    double array[ARRAY_SIZE];

    while (currentPickedOption != EXIT)
    {
        printMenuOptions();
        currentPickedOption = getMenuOption();

        switch (currentPickedOption) {

            case MANUAL_INPUT: {
                printf("Input %d variables: \n", ARRAY_SIZE);

                for (int i = 0; i < ARRAY_SIZE; ++i) {
                    printf("%d element:", i + 1);
                    array[i] = getDoubleInput();
                }

                solveMath(array, ARRAY_SIZE);
                break;
            }
            case RANDOM_INPUT: {
                fillDoubleArray(ARRAY_SIZE, array);

                solveMath(array, ARRAY_SIZE);
                break;
            }
            case CLEAR_CONSOLE: {
                system("cls");
                break;
            }
            case EXIT: {
                puts("Exiting...");
                break;
            }
            default:{
                onInvalidInput("enter a valid option!\n");
                break;
            }
        }
    }

    return EXIT_SUCCESS;
}
