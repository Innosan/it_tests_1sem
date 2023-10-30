#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include "math_utils.h"
#include "menu.h"

void solveMath(double x, double y, double z) {
    double zeroValidator = (z + pow(x, 2) / 4); // validating division by zero
    double logValidator = (y - sqrt(fabs(x))) * (x - y / zeroValidator); // validating log of 0

    if (zeroValidator == 0) {
        printf("\nDivision by 0 is prohibited!\n\n");

        return;
    } else if (logValidator == 0) {
        printf("\nLog of 0 is prohibited!\n\n");

        return;
    }
    else {
        double f = 0.;
        f = log(fabs(logValidator));

        printf("\nF: %f\n\n", f);
    }
}

int main(void) {
    srand(time(NULL));

	int currentPickedOption = -1;

	double x = 0.;
	double y = 0.;
	double z = 0.;

	getWelcomeMessage(getStudent(), 1, 1);

	while (currentPickedOption != EXIT)
	{
		printMenuOptions();
        currentPickedOption = getMenuOption();

		switch (currentPickedOption) {

            case MANUAL_INPUT: {
                bool isArgsValid = false;

                puts("Input 3 variables: ");

                do {
                    if (scanf("%lf %lf %lf", &x, &y, &z) == 3) {
                        printf("Valid input: %f, %f, %f\n", x, y, z);
                        while (getchar() != '\n');

                        isArgsValid = true;
                    }
                    else {
                        while (getchar() != '\n');
                        onInvalidInput("enter only double values");
                    }
                } while (!isArgsValid);

                solveMath(x, y, z);
                break;
            }
            case RANDOM_INPUT: {
                x = getRandomNumber(MIN_RANDOM, MAX_RANDOM);
                y = getRandomNumber(MIN_RANDOM, MAX_RANDOM);
                z = getRandomNumber(MIN_RANDOM, MAX_RANDOM);

                printf("\nRandom X: %f\nRandom Y: %f\nRandom Z: %f", x, y, z);

                solveMath(x, y, z);
                break;
            }
            case CLEAR_CONSOLE: {
                system("cls");
                break;
            }
            case EXIT: {
                puts("Exiting...");
                break;
            }
            default:{
                onInvalidInput("enter a valid option!\n");
                break;
            }
		}
	}

	return EXIT_SUCCESS;
}
