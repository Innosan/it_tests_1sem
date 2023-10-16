#define MATH_UTILS_H
#include "task_structures.h"

/**
 * Displays a welcome message with information about a student, test, task, and variant.
 *
 * @param stud The student structure containing the student's name, group number, and personal number.
 * @param test The test number.
 * @param task The task number.
 */
void getWelcomeMessage(struct student stud, int test, int task);

/**
 * Generates a random number within a specified range.
 *
 * @param from - the lower bound of the range.
 * @param to - the upper bound of the range.
 * @return a random number within the specified range.
 */
double getRandomNumber(double from, double to);

/**
 * Displays a message about invalid input then clears input.
 *
 * @param message - the invalid input message.
 */
void onInvalidInput(char *message);

typedef enum {
    MIN_RANDOM = -25,
    MAX_RANDOM = 25,
} RandomRange;

#undef MATH_UTILS_H
