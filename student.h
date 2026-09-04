#ifndef STUDENT_H
#define STUDENT_H

typedef struct{
    int id;
    char name[50];
    int age;
    float marks;
} Student;

void addStudent(Student *students);
void loadStudents(Student *students, int *count);

#endif