#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "math_utils.h"

/**
 * Solves the recurrence relation
 * @param l - the length of the recurrence
 * @return the sum of the recurrence
 */
double solveRecurrence(int l) {
    if (l == 1) {
        return 1.5; // base case 1
    } else if (l == 2) {
        return 2.0; // base case 2
    } else {
        // caching 2 previous elements
        double prev1 = 2.0;
        double prev2 = 1.5;

        double current;

        double sum = prev1 + prev2;
        for (int i = 3; i <= l; i++) {
            current = 2.5 * sin(prev1 - prev2) + 3 * cos(prev1 + prev2);

            sum += current;

            prev2 = prev1;
            prev1 = current;
        }

        return sum;
    }
}

int main(void) {
    int l = 150;

    getWelcomeMessage(getStudent(), 2, 1);
    double sum = solveRecurrence(l);

    printf("Sum of the recurrence from 1 to %d is %f\n", l, sum);

    return EXIT_SUCCESS;
}
