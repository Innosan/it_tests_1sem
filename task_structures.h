#ifndef IT_TESTS_1SEM_TASK_STRUCTURES_H
#define IT_TESTS_1SEM_TASK_STRUCTURES_H

typedef struct student student;

struct student {
    char name[50];
    int groupNumber;
    int personalNumber;
};

struct student getStudent(void);

#endif //IT_TESTS_1SEM_TASK_STRUCTURES_H
