#ifndef STUDENT_H
#define STUDENT_H

typedef struct{

    int id;
    char name[50];
    int age;
    float marks;

} Student;

void addStudent(Student *students, int count);

void loadStudents(Student *students, int *count);

void searchStudent(Student *students, int count, int id);

void deleteStudent(Student *students, int *count, int id);

void updateStudent(Student *students, int count, int id);

int studentExists(Student *students, int count, int id);

void sortStudents(Student *students, int count);

#endif