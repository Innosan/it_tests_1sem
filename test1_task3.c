#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <corecrt_math_defines.h>
#include "math_utils.h"

// TODO: deal with 0.20000 output
int main(void) {
	char* locale = setlocale(LC_ALL, "");

	getWelcomeMessage(getStudent());

	double y = 0.;

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