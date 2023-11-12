#include <stdio.h>
#include "menu.h"
#include "math_utils.h"

void printMenuOptions(void) {
    printf("\n\nInput %d to solve math problem with manual input.\n", MANUAL_INPUT);
    printf("Input %d to solve math problem with random variables.\n", RANDOM_INPUT);
    printf("Input %d to clear console.\n", CLEAR_CONSOLE);
    printf("Input %d to exit!\n", EXIT);

    printf("\nPick option:");
}

int getMenuOption(void) {
    int pickedOption = 0;

    while (scanf("%d", &pickedOption) != 1) {

        while (getchar() != '\n');

        return 0;
    }

    while (getchar() != '\n');
    return pickedOption;
}
