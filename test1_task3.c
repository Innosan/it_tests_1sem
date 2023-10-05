#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "math_utils.h"

int main(void) {
	getWelcomeMessage(getStudent(), 1, 3);

	double y = 0.;

    // calculating y for x in range [-1.0, 2.0] with step 0.2
    for (int x = -10; x <= 20; x += 2) {
        double factor = (double) x / 10;

        if (factor < -0.2) {
            y = M_PI / factor + sin(M_PI / factor);

            printf("For x = %.2lf, y = %.2lf\n", factor, y);
        }
        else {
            if (factor > 0.0) {
                y = M_PI * factor / 2;

                printf("For x = %.2lf, y = %.2lf\n", factor, y);
            }
            else {
                printf("For x = 0, y = 0\n");
            }
        }
    }

	return EXIT_SUCCESS;
}
