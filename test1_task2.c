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
        puts("Picked first evaluation!");
        double nonNegativeResult = x + fabs(y * z);

        if (nonNegativeResult < 0) {
            puts("Cannot get sqrt of negative value!");
            return;
        }

		n = sin(x) + 0.5 * (sqrt(nonNegativeResult));
	}
	else if (y <= 1) {
        puts("Picked second evaluation!");
        double nonNegativeResult = pow(x, 2) + z;

        if (nonNegativeResult < 0) {
            puts("Cannot get sqrt of negative value!");
            return;
        }

		n = 2 * y * sqrt(nonNegativeResult);
	}
	else {
        puts("Picked third evaluation!");
		n = 3 * pow(x, 3) - 2 * pow(y, 2) + z;
	}

    printf("\nF: %f\n\n", n);
}

int main(void) {
    srand(time(NULL));

	int currentPickedOption = -1;

	double x = 0.;
	double y = 0.;
	double z = 0.;

	getWelcomeMessage(getStudent(), 1, 2);

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
                        printf("Valid input: %lf, %lf, %lf\n", x, y, z);
                        while (getchar() != '\n');

                        isArgsValid = true;
                    } else {
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
                onInvalidInput("enter a valid option\n");
                break;
            }
        }
	}

	return EXIT_SUCCESS;
}
