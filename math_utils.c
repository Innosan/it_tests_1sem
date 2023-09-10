#include "stdio.h"
#include <stdlib.h>
#include "math_utils.h"

void getWelcomeMessage(
	struct student stud
) {
	printf(
		"%s, %d, \nTest ¹%d, task %d, number %d\n\n",
		stud.name, stud.groupNumber, stud.testNumber, stud.taskNumber, stud.variant
	);
}

struct student getStudent(void) {
	struct student stud = {
		"Fomin Mikhail Vital\'evich",
		4307,
		1,
		1,
		26
	};

	return stud;
};

double getRandomNumber(double from, double to)
{
	double range = (to - from);
	double div = RAND_MAX / range;

	return from + (rand() / div);
}
