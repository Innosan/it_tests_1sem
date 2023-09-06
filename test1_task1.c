#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include "math_utils.h"

void solveMath(double x, double y, double z) {
	// TODO: make validation for inf cases

    double f = 0.;

	f = log(fabs((y - sqrt(fabs(x))) * (x - y / (z + pow(x, 2) / 4))));
    printf("\nF: %f\n\n", f);
}

int main(void) {
	setlocale(LC_ALL, "");

	int currentPickedOption = -1;

	double x = 0.;
	double y = 0.;
	double z = 0.;

	getWelcomeMessage(getStudent());

	while (currentPickedOption != 0)
	{
		printf("Input '1' to solve math problem with manual input.\n");
		printf("Input '2' to solve math problem with random variables.\n");
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
		default:
			break;
		}
	}

	return EXIT_SUCCESS;
}
