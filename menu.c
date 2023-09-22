#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void printMenuOptions(void) {
    printf("Input '1' to solve math problem with manual input.\n");
    printf("Input '2' to solve math problem with random variables.\n");
    printf("Input '3' to clear console.\n");
    printf("Input '9' to exit!\n");

    printf("\nPick option:");
}

int getMenuOption(void) {
    char pickedOption[80];
    scanf("%s", pickedOption);

    return atoi(pickedOption);
}
