#ifndef IT_TESTS_1SEM_MENU_H
#define IT_TESTS_1SEM_MENU_H

/**
 * Prints menu options
 */
void printMenuOptions(void);

/**
 * Gets picked option from user
 * @return picked option
 */
int getMenuOption(void);

typedef enum {
    MANUAL_INPUT = 1,
    RANDOM_INPUT,
    CLEAR_CONSOLE,
    EXIT,
} MenuOption;

#endif //IT_TESTS_1SEM_MENU_H
