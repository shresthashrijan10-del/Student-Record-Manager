#include <stdio.h>
#include "student.h"
void addStudent(Student *students){
    printf("Enter id: ");
    scanf("%d",&students->id);

    printf("Enter name: ");
    scanf("%49s",students->name);

    printf("Enter age: ");
    scanf("%d",&students->age);

    printf("Enter marks: ");
    scanf("%f",&students->marks);
}
void loadStudents(Student *students, int *count){
    FILE *fp;

    fp = fopen("student.data", "rb");

    if(fp == NULL){
        return;
    }

    fseek(fp, 0, SEEK_END);

    long fileSize = ftell(fp);

    *count = fileSize / sizeof(Student);

    fseek(fp, 0, SEEK_SET);

    fread(students, sizeof(Student), *count, fp);

    fclose(fp);
}
void searchStudent(Student *students,int count,int id){
    for(int i=0;i<count;i++){
        if(students[i].id==id){
            printf("\nStudent found!\n");
            printf("ID: %d\n",students[i].id);
            printf("Name: %s\n",students[i].name);
            printf("Age: %d\n",students[i].age);
            printf("Marks: %.2f\n",students[i].marks);
            return;
        }

    }
    printf("\nStudent not found.\n");
}