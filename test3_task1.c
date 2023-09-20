#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "math_utils.h"
#include "arrays.h"

int main(void) {
    srand(time(NULL));

    getWelcomeMessage(getStudent(), 3, 1);

    int matrixDegree = 1;
    int isArgValid = 0;

    // 26 and -26 because we're filling array within -25 to 25 range
    double max = -26;
    double min = 26;

    printf("Input matrix degree:");
    do {
        if (scanf("%d", &matrixDegree) == 1 && matrixDegree > 1) {
            printf("Valid input: %d\n", matrixDegree);
            isArgValid = 1;
        }
        else {
            onInvalidInput("enter only int values from 2 to N");
        }
    } while (isArgValid != 1);

    double matrix[matrixDegree][matrixDegree];

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

    printf("\n\nMax element: %f, min element: %f", max, min);

    return EXIT_SUCCESS;
}
