#define MATH_UTILS_H

void getWelcomeMessage(struct student stud);

/**
 * Generates a random number within a specified range.
* 
 * @param from - the lower bound of the range.
 * @param to - the upper bound of the range.
 * @return a random number within the specified range.
 */
double getRandomNumber(double from, double to);

struct student getStudent();

struct student {
	char name[50];
	int groupNumber;
	int testNumber;
	int taskNumber;
	int variant;
};