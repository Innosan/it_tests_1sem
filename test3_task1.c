// system libs
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// dev libs
#include "math_utils.h"
#include "arrays.h"
#include "menu.h"
#include "inputs.h"
#include "memory.h"

/**
 * Finds the minimum and maximum elements
 * below sub-diagonal in a 2D array (matrix).
 *
 * @param rows - The number of rows in the 2D array.
 * @param cols - The number of columns in the 2D array.
 * @param array - The 2D array to be processed.
 */
void solveTask(int rows, int cols, double **array) {

    // init min and max to the last element of the first row of the array
    double min = array[0][cols - 1];
    double max = array[0][cols - 1];

    print2dDynamicDoubleArray(rows, cols, array);

    puts("\nIn field:");
    for (int i = 0; i < rows; ++i) {
        puts("");
        /**
         * loop over each column in reverse order, starting from the last column
         * and stopping at the element of sub-diagonal.
         */
        for (int j = cols - 1; j > cols - i - 2; --j) {
            printf("%6.2f ", array[i][j]);

            // finding min and max
            if (array[i][j] >= max) {
                max = array[i][j];
            } else if (array[i][j] <= min) {
                min = array[i][j];
            }
        }
    }

    printf("\n\nMax element: %f, min element: %f", max, min);
}

int main(void) {
    srand(time(NULL));

    getWelcomeMessage(getStudent(), 3, 1);

    int currentPickedOption = -1;

    while (currentPickedOption != EXIT)
    {
        printMenuOptions();
        currentPickedOption = getMenuOption();

        int matrixDegree = 1;

        switch (currentPickedOption) {

            case MANUAL_INPUT: {
                while (matrixDegree <= 1) {
                    printf("Input matrix degree:");
                    matrixDegree = getIntInput();

                    if (matrixDegree <= 1) {
                        puts("Degree should be more than 1!");
                    }
                }

                double **matrix = allocate2dArray(matrixDegree, matrixDegree);
                manualFill2dDoubleArray(matrixDegree, matrixDegree, matrix);

                solveTask(matrixDegree, matrixDegree, matrix);

                free2dArray(matrixDegree, matrix);
                break;
            }
            case RANDOM_INPUT: {
                matrixDegree = (int) getRandomNumber(2, 10);
                printf("\nRandom matrix degree: %d\n", matrixDegree);

                double **matrix = allocate2dArray(matrixDegree, matrixDegree);
                fill2dDynamicDoubleArray(matrixDegree, matrixDegree, matrix);

                solveTask(matrixDegree, matrixDegree, matrix);

                free2dArray(matrixDegree, matrix);
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
