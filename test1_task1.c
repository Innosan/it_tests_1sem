#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include "math_utils.h"

void solveMath(double x, double y, double z) {
    double f = 0.;
    double validator = (z + pow(x, 2) / 4);

    if (validator == 0) {
        printf("\nDivision by zero!\n\n");
        return;
    } else {
        f = log(fabs((y - sqrt(fabs(x))) * (x - y / validator)));

        printf("\nF: %f\n\n", f);
    }
}

void runTests(void) {
    puts("Running tests...");

    puts("Test 1: expected result is value of F");

    puts("Test 2: expected result is value of F");
    solveMath(0, 2, -8);

    puts("Test 3: expected result is value of F");
    solveMath(-5, -2, -3);

    puts("Test 4: expected result is value of F");
    solveMath(1000, 500, 200);

    puts("Test 5: expected result is printing division by zero");
    solveMath(0, 0, 0);
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
					printf("Valid input: %lf, %lf, %lf\n", x, y, z);
					isArgsValid = true;
				}
				else {
					printf("Invalid input. Please enter only double values.\n");
					while (getchar() != '\n');
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
            runTests();
        }
		default:
			break;
		}
	}

	return EXIT_SUCCESS;
}
