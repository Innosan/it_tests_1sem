#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "math_utils.h"

double solveRecurrence(int l) {
    if (l == 1) {
        return 1.5;
    } else if (l == 2) {
        return 2.0;
    } else {
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
    int n = 150;

    getWelcomeMessage(getStudent(), 2, 1);
    double sum = solveRecurrence(n);

    printf("Sum of the recurrence from 1 to %d is %f\n", n, sum);

    return EXIT_SUCCESS;
}
