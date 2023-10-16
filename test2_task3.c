#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "math_utils.h"
#include "arrays.h"

int main(void) {
    srand(time(NULL));

    int n = 6;
    int m = 6;
    int mainMatrix[n][m];
    int mainDiagonal[n];
    int transformedMatrix[n][m];

    getWelcomeMessage(getStudent(), 2, 3);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            mainMatrix[i][j] = (int) getRandomNumber(MIN_RANDOM, MAX_RANDOM);

            if (i == j) {
                mainDiagonal[i] = mainMatrix[i][j];

                for (int k = 0; k < j; ++k) {
                    printf("%d ", mainMatrix[i][k]);
                }
            }
        }
    }

    puts("\nMain Diagonal: ");
    printIntArray(n, mainDiagonal);

    puts("\n\nMain Matrix: ");
    print2dIntArray(n, m, mainMatrix);

    return EXIT_SUCCESS;
}
