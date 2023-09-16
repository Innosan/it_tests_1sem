#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include "math_utils.h"

void solveMath(double x, double y, double z) {
    double validator = (z + pow(x, 2) / 4); // validating division by zero
    double validator2 = (y - sqrt(fabs(x))) * (x - y / validator); // validating log of 0

    if (validator == 0 || validator2 == 0) {
        printf("\nDivision by zero or log of 0!\n\n");
        return;
    } else {
        double f = 0.;
        f = log(fabs(validator2));

        printf("\nF: %f\n\n", f);
    }
}

int main(void) {
	int currentPickedOption = -1;

	double x = 0.;
	double y = 0.;
	double z = 0.;

	getWelcomeMessage(getStudent(), 1, 1);

	while (currentPickedOption != 0)
	{
		printf("Input '1' to solve math problem with manual input.\n");
		printf("Input '2' to solve math problem with random variables.\n");
		printf("Input '3' to run tests!\n");
		printf("Input '0' to exit!\n");

		scanf("%d", &currentPickedOption);
		switch (currentPickedOption) {

		case 1: {
			bool isArgsValid = false;

			puts("Input 3 variables: ");

			do {
				if (scanf("%lf %lf %lf", &x, &y, &z) == 3) {
					printf("Valid input: %f, %f, %f\n", x, y, z);
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
        case 3: {
            puts("Running tests...");
        }
		default:
			break;
		}
	}

	return EXIT_SUCCESS;
}
