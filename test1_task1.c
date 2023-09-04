#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include "math_utils.h"

/*
worth to mention: before ctrlc-v to pelles, you need to change all scanf_s's to scanf!
*/

double solveMath(double x, double y, double z) {
	// TODO: make validation for inf cases

	return log(fabs((y - sqrt(fabs(x))) * (x - y / (z + pow(x, 2) / 4))));
}

int main(void) {
	char* locale = setlocale(LC_ALL, "");

	int currentPickedOption = -1;

	double x = 0.;
	double y = 0.;
	double z = 0.;

	double f = 0.;

	getWelcomeMessage(getStudent());

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
					printf("Invalid input. Please enter only double values.\n");
					while (getchar() != '\n');
				}
			} while (isArgsValid == false);

			f = solveMath(x, y, z);

			printf("\nF: %f\n\n", f);
			break;
		}
		case 2: {
			srand(time(NULL));

			x = getRandomNumber(-25, 25);
			y = getRandomNumber(-25, 25);
			z = getRandomNumber(-25, 25);

			printf("\nRandom X: %f\nRandom Y: %f\nRandom Z: %f", x, y, z);

			f = solveMath(x, y, z);
			printf("\nF: %f\n\n", f);

			break;
		}
		default:
			break;
		}
	}

	return EXIT_SUCCESS;
}