#include <stdio.h>
#include "inputs.h"

double getDoubleInput(void) {
    double input = 0.;

    while (scanf("%lf", &input) != 1) {
        while (getchar() != '\n');
        puts("Only double numbers allowed. Try again!");
    }

    while (getchar() != '\n');
    return input;
}

int getIntInput(void) {
    int input = 0;

    while (scanf("%d", &input) != 1) {
        while (getchar() != '\n');
        puts("Only int numbers allowed. Try again!");
    }

    while (getchar() != '\n');
    return input;
}
