#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "math_utils.h"

int main(void) {
	getWelcomeMessage(getStudent(), 1, 3);

	double y = 0.;

    // calculating y for x in range [-1.0, 2.0) with step 0.2
    for (double x = -1.0; x < 2.0; x += 0.2) {
        if (x < -0.2) {
            y = M_PI / x + sin(M_PI / x);

            printf("For x = %lf, y = %lf\n", x, y);
        }
        else {
            if (x > 0.0) {
                y = M_PI * x / 2;

                printf("For x = %lf, y = %lf\n", x, y);
            }
            else {
                printf("For x = 0, y = 0\n");
            }
        }
    }

	return EXIT_SUCCESS;
}
