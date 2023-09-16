#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include "math_utils.h"

void solveMath(double x, double y, double z) {
    // validating infinity cases
    double firstValidator = x + fabs(y * z);
    double secondValidator = pow(x, 2) + z;

    if (firstValidator < 0 || secondValidator < 0) {
        printf("\nUnable to get sqrt from negative value!\n\n");
        return;
    }

    double n = 0.;

	if (y < -3) {
		n = sin(x) + 0.5 * (sqrt(firstValidator));
	}
	else if (y <= 1) {
		n = 2 * y * sqrt(secondValidator);
	}
	else {
		n = 3 * pow(x, 3) - 2 * pow(y, 2) + z;
	}

    printf("\nF: %f\n\n", n);
}

int main(void) {
	int currentPickedOption = -1;

	double x = 0.;
	double y = 0.;
	double z = 0.;

	getWelcomeMessage(getStudent(), 1, 2);

	while (currentPickedOption != 0)
	{
		printf("Input '1' to solve math problem with manual input.\n");
		printf("Input '2' to solve math problem with random variables.\n");
		printf("Input '0' to exit!\n");

		scanf_s("%d", &currentPickedOption);
		switch (currentPickedOption) {

		case 1: {
			bool isArgsValid = false;

			puts("Input 3 variables: ");

			do {
				if (scanf_s("%lf %lf %lf", &x, &y, &z) == 3) {
					printf("Valid input: %lf, %lf, %lf\n", x, y, z);
					isArgsValid = true;
				}
				else {
                    onInvalidInput("enter only double values");
				}
			} while (isArgsValid == false);

			solveMath(x, y, z);
			break;
		}
		case 2: {
			srand(time(NULL));

			x = getRandomNumber(-25, 25);
			y = getRandomNumber(-25, 25);
			z = getRandomNumber(-25, 25);

			printf("\nRandom X: %f\nRandom Y: %f\nRandom Z: %f", x, y, z);

			solveMath(x, y, z);
			break;
		}
		default:
			break;
		}
	}

	return EXIT_SUCCESS;
}
