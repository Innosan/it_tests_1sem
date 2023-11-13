#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "math_utils.h"
#include "arrays.h"
#include "menu.h"
#include "inputs.h"

#define MATRIX_DEGREE 6

void solveMath(int rows, int cols, int (*array)[cols]) {
    puts("\n\nOriginal Matrix: ");
    print2dIntArray(rows, cols, array);

    /**
     * needed for storing sum of elements
     * behind an element of main diagonal
     */
    int sumVector[MATRIX_DEGREE] = { 0 };

    for (int i = 0; i < rows; ++i) {
        int sumOfRow = 0;

        for (int j = 0; j < cols; ++j) {

            // picking only elems of main diagonal != 0
            if (i == j && array[i][j] != 0) {

                // calculating sum of elems behind elem of main diagonal
                for (int k = j + 1; k < cols; ++k) {
                    sumOfRow += array[i][k];
                }

                array[i][j] = sumOfRow;
                sumVector[i] = sumOfRow;
            }
        }
    }

    puts("\nSum vector: ");
    printIntArray(MATRIX_DEGREE, sumVector);

    puts("\n\nModified Matrix: ");
    print2dIntArray(rows, cols, array);
}

int main(void) {
    srand(time(NULL));
    getWelcomeMessage(getStudent(), 2, 3);

    int currentPickedOption = -1;

    int matrix[MATRIX_DEGREE][MATRIX_DEGREE] = {0};

    while (currentPickedOption != EXIT)
    {
        printMenuOptions();
        currentPickedOption = getMenuOption();

        switch (currentPickedOption) {

            case MANUAL_INPUT: {
                printf("Input %d variables: \n", MATRIX_DEGREE * 2);

                for (int i = 0; i < MATRIX_DEGREE; ++i) {
                    for (int j = 0; j < MATRIX_DEGREE; ++j) {
                        printf("[%d][%d] element:", i + 1, j + 1);
                        matrix[i][j] = getIntInput();
                    }
                }

                solveMath(MATRIX_DEGREE, MATRIX_DEGREE, matrix);
                break;
            }
            case RANDOM_INPUT: {
                fill2dIntArray(MATRIX_DEGREE, MATRIX_DEGREE, matrix);

                solveMath(MATRIX_DEGREE, MATRIX_DEGREE, matrix);
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
