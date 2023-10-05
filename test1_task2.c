#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include "math_utils.h"
#include "menu.h"

void solveMath(double x, double y, double z) {
    double n = 0.;

	if (y < -3) {
        double nonNegativeResult = x + fabs(y * z);

        if (nonNegativeResult < 0) {
            return;
        }

		n = sin(x) + 0.5 * (sqrt(nonNegativeResult));
	}
	else if (y <= 1) {
        double nonNegativeResult = pow(x, 2) + z;

        if (nonNegativeResult < 0) {
            return;
        }

		n = 2 * y * sqrt(nonNegativeResult);
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

	while (currentPickedOption != 3)
	{
		printMenuOptions();
        currentPickedOption = getMenuOption();

		switch (currentPickedOption) {

            case MANUAL_INPUT: {
                bool isArgsValid = false;

                puts("Input 3 variables: ");

                do {
                    if (scanf("%lf %lf %lf", &x, &y, &z) == 3) {
                        printf("Valid input: %lf, %lf, %lf\n", x, y, z);
                        isArgsValid = true;
                    } else {
                        onInvalidInput("enter only double values");
                    }
                } while (!isArgsValid);

                solveMath(x, y, z);
                break;
            }
            case RANDOM_INPUT: {
                srand(time(NULL));

                x = getRandomNumber(-25, 25);
                y = getRandomNumber(-25, 25);
                z = getRandomNumber(-25, 25);

                printf("\nRandom X: %f\nRandom Y: %f\nRandom Z: %f", x, y, z);

                solveMath(x, y, z);
                break;
            }
            case EXIT: {
                puts("Exiting...");
                break;
            }
            default:{
                onInvalidInput("enter a valid option\n");
                break;
            }
        }
	}

	return EXIT_SUCCESS;
}
