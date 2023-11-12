#include <stdio.h>
#include <stdlib.h>
#include "math_utils.h"

void getWelcomeMessage(struct student stud, int test, int task) {
	printf(
		"%s, group %d\nTest %d, task %d, variant %d",
		stud.name,
        stud.groupNumber,
        test,
        task,
        stud.personalNumber
	);
}

struct student getStudent(void) {
    struct student myself = {
            "Fomin Mikhail Vital\'evich",
            4307,
            26,
    };

	return myself;
}

double getRandomNumber(double from, double to)
{
	double range = (to - from);
	double div = RAND_MAX / range;

	return from + (rand() / div);
}

void onInvalidInput(char *message) {
    printf("Invalid input: %s\n", message);
}
