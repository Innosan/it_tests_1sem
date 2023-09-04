#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>

/*
worth mention: before ctrlc-v to pelles, you need to change all scanf_s's to scanf!
*/


void generateWelcomeMessage(
	char* userFio,
	int groupNumber,
	int testNumber,
	int taskNumber,
	int variant
) {
	printf(
		"%s, %d, \nКонтрольная №%d, задание %d, вариант %d\n\n",
		userFio, groupNumber, testNumber, taskNumber, variant
	);
}

int main(void) {
	//turnung messy kinda-cyrillic text in console into readable chars
	char* locale = setlocale(LC_ALL, "");

	int currentPickedOption = -1;

	double x = 0.;
	double y = 0.;
	double z = 0.;

	double f = 0.;

	generateWelcomeMessage(
		"Фомин Михаил Витальевич",
		4307,
		1,
		1,
		26
	);

	while (currentPickedOption != 0)
	{
		printf("Input '1' to solve math problem with manual input.\n");
		printf("Input '2' to solve math problem with random variables.\n");
		printf("Input '0' to exit!\n");

		scanf_s("%d", &currentPickedOption);
		switch (currentPickedOption) {

		case 1: {
			bool isArgsValid = false;

			puts("Input 3 variables: ");

			do {
				if (scanf_s("%lf %lf %lf", &x, &y, &z) == 3) {
					printf("Valid input: %lf, %lf, %lf\n", x, y, z);
					isArgsValid = true;
				}
				else {
					printf("Invalid input. Please enter only double values.\n");
					while (getchar() != '\n');
				}
			} while (isArgsValid == false);

			f = log(fabs((y - sqrt(fabs(x))) * (x - y / (z + pow(x, 2) / 4))));

			printf("\nF: %f\n\n", f);
			break;
		}
		case 2: {
			// TODO: solve math with random numbers;

			break;
		}
		default:
			break;
		}
	}

	return EXIT_SUCCESS;
}