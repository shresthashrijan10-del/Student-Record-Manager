#include <stdio.h>
#include "student.h"

int studentExists(Student *students, int count, int id){

    for(int i = 0; i < count; i++){

        if(students[i].id == id){
            return 1;
        }
    }

    return 0;
}

void addStudent(Student *students, int count){

    do{
        printf("Enter id: ");
        scanf("%d", &students[count].id);

        if(studentExists(students, count, students[count].id)){
            printf("This ID already exists. Enter another ID.\n");
        }

    }while(studentExists(students, count, students[count].id));


    printf("Enter name: ");
    scanf("%49s", students[count].name);


    do{
        printf("Enter age: ");
        scanf("%d", &students[count].age);

        if(students[count].age <= 0){
            printf("Enter the correct age.\n");
        }

    }while(students[count].age <= 0);


    do{
        printf("Enter Marks: ");
        scanf("%f", &students[count].marks);

        if(students[count].marks < 0 || students[count].marks > 100){
            printf("Invalid marks. Enter a value between 0 and 100.\n");
        }

    }while(students[count].marks < 0 || students[count].marks > 100);
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


void searchStudent(Student *students, int count, int id){

    for(int i = 0; i < count; i++){

        if(students[i].id == id){

            printf("\nStudent found!\n");
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            printf("Marks: %.2f\n", students[i].marks);

            return;
        }
    }

    printf("\nStudent not found.\n");
}


void deleteStudent(Student *students, int *count, int id){

    int foundIndex = -1;

    for(int i = 0; i < *count; i++){

        if(students[i].id == id){

            foundIndex = i;
            break;
        }
    }

    if(foundIndex == -1){

        printf("Could not find the student.\n");
        return;
    }

    for(int j = foundIndex; j < (*count - 1); j++){

        students[j] = students[j + 1];
    }

    (*count)--;

    printf("Student deleted successfully.\n");
}


void updateStudent(Student *students, int count, int id){

    int found = 0;

    for(int i = 0; i < count; i++){

        if(students[i].id == id){

            printf("Enter new name: ");
            scanf("%49s", students[i].name);

            printf("Enter new age: ");
            scanf("%d", &students[i].age);

            printf("Enter new marks: ");
            scanf("%f", &students[i].marks);

            printf("Updated successfully.\n");

            found = 1;
            break;
        }
    }

    if(found == 0){
        printf("Student not found.\n");
    }
}
void sortStudents(Student *students,int count){
    for(int i=0;i<count-1;i++){
        for(int j=0;j<count-1-i;j++){
            if(students[j].marks>students[j+1].marks){
                Student temp;
                temp=students[j];
                students[j]=students[j+1];
                students[j+1]=temp;
            }
        }
    }
}
void findTopStudent(Student *students,int count){
     int top=0;
    for (int i=1;i<count;i++){
       
        if(students[i].marks>students[top].marks){
             top=i;
        }
         
    }
    printf("Top Student\n");
    printf("Name: %s\n",students[top].name);
    printf("Id: %d\n",students[top].id);
    printf("Age: %d\n",students[top].age);
    printf("%.2f\n",students[top].marks);
}