#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "arrays.h"
#include "math_utils.h"

#define ARRAY_SIZE 25

int main(void) {
    srand(time(NULL));

    getWelcomeMessage(getStudent(), 2, 2);
    double array[ARRAY_SIZE];

    // 26 and -26 because we're filling array within -25 to 25 range
    double maxElem = -26.;
    double minElem = 26.;
    int maxElemIndex = 0;
    int minElemIndex = 0;

    int p = 0;

    fillDoubleArray(ARRAY_SIZE, array);
    printDoubleArray(ARRAY_SIZE, array);

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
    if (minElemIndex > maxElemIndex) {
        p = (minElemIndex + maxElemIndex) / 2;
    } else p = (maxElemIndex + minElemIndex) / 2;

    printf("\n\nMax elem: %.2f with index %d", maxElem, maxElemIndex);
    printf("\nMin elem: %.2f with index %d", minElem, minElemIndex);
    printf("\n\nP: %d", p);

    puts("\n\nX sequence: ");
    for (int i = 0; i <= p; ++i) {
        printf("%6.2f, ", array[i]);
    }

    puts("\nY sequence: ");
    for (int i = p + 1; i < ARRAY_SIZE; ++i) {
        printf("%6.2f, ", array[i]);
    }

    return EXIT_SUCCESS;
}
