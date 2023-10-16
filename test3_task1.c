#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "math_utils.h"
#include "arrays.h"
#include "menu.h"

/**
 * Finds out min and max element below matrix's sub-diagonal.
 * @param matrixDegree - matrix degree (6 is 6x6 matrix, for example)
 */
void solveTask(int matrixDegree) {
    double matrix[matrixDegree][matrixDegree];

    // 26 and -26 because we're filling array within -25 to 25 range
    double max = -26;
    double min = 26;

    fill2dDoubleArray(matrixDegree, matrixDegree, matrix);
    print2dDoubleArray(matrixDegree, matrixDegree, matrix);

    puts("\nIn field:");
    for (int i = 0; i < matrixDegree; ++i) {
        puts("");

        for (int j = matrixDegree - 1; j > matrixDegree - i - 2; --j) {
            printf("%.2f ", matrix[i][j]);

            if (matrix[i][j] >= max) {
                max = matrix[i][j];
            } else if (matrix[i][j] <= min) {
                min = matrix[i][j];
            }
        }
    }

    printf("\n\nMax element: %f, min element: %f\n\n", max, min);
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
                bool isArgValid = false;

                do {
                    printf("Input matrix degree:");

                    if (scanf("%d", &matrixDegree) == 1 && matrixDegree > 1) {
                        printf("Valid input: %d\n", matrixDegree);
                        isArgValid = 1;
                    }
                    else {
                        while (getchar() != '\n');
                        onInvalidInput("enter only int values from 2 to N");
                    }
                } while (!isArgValid);

                solveTask(matrixDegree);
                break;
            }
            case RANDOM_INPUT: {
                matrixDegree = (int) getRandomNumber(1, 10);

                printf("\nRandom matrix degree: %d\n", matrixDegree);

                solveTask(matrixDegree);
                break;
            }
            case CLEAR_CONSOLE: {
                system("cls");
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
