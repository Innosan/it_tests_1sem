#include <stdio.h>
#include "menu.h"

void printMenuOptions(void) {
    printf("Input %d to solve math problem with manual input.\n", MANUAL_INPUT);
    printf("Input %d to solve math problem with random variables.\n", RANDOM_INPUT);
    printf("Input %d to clear console.\n", CLEAR_CONSOLE);
    printf("Input %d to exit!\n", EXIT);

    printf("\nPick option:");
}

int getMenuOption(void) {
    int pickedOption = 0;

    while (1) {
        if (scanf("%d", &pickedOption) == 1) {
            while (getchar() != '\n');

            return pickedOption;
        } else {
            while (getchar() != '\n');
            puts("Please, enter valid option!");
        };
    }
}
