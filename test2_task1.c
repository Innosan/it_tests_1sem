#include "stdio.h"
#include "math.h"
#include "math_utils.h"

double memo[1000];

double solveReccurenceWithArray(int l) {
    if (l == 1) {
        return 1.5;
    } else if (memo[l] != 0) {
        return memo[l]; // Return the precomputed value if available
    } else if (l > 2) {
        double f = 0.;

        f = 2.5 * sin(solveReccurenceWithArray(l - 1) - solveReccurenceWithArray(l -2)) + 3 * cos(solveReccurenceWithArray(l - 1) + solveReccurenceWithArray(l - 2));
        memo[l] = f;

        return f;
    } else return 2.;
}

double solveReccurenceWithPrevs(int l) {
    static double prev1 = 1.5; // Variable to store the previous value
    static double prev2 = 2.0;

    if (l == 1) {
        return prev1;
    } else if (l == 2) {
        return prev2; // Return the precomputed value if available
    } else {
        double f = 0.;
        f = 2.5 * sin(solveReccurenceWithPrevs(l - 1) - solveReccurenceWithPrevs(l -2)) + 3 * cos(solveReccurenceWithPrevs(l - 1) + solveReccurenceWithPrevs(l - 2));
        prev2 = prev1;
        prev1 = f;
        return f;
    }
}

int main(void) {
    int n = 15;

    getWelcomeMessage(getStudent());

    printf("Fibonacci of %d is %f\n", n, solveReccurenceWithArray(n));
}
