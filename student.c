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
void deleteStudent(Student *students,int *count,int id){
    int foundIndex=-1;
    for(int i=0;i<*count;i++){
        if(students[i].id==id){
            foundIndex=i;
            break;
        }
    }
    if(foundIndex==-1){
        printf("Could not find the student.\n");
        return;
    }
    for(int j=foundIndex;j<(*count-1);j++){
        students[j]=students[j+1];
       
    }
     (*count)--;
    
}
void updateStudent(Student *students,int count,int id){
    int found=0;
    for(int i=0;i<count;i++){
        if(students[i].id==id){
            printf("Enter new name: \n");
            scanf("%49s",students[i].name);

            printf("Enter new age: \n");
            scanf("%d",&students[i].age);

            printf("Enter new marks: \n");
            scanf("%f",&students[i].marks);

            printf("Updated successfully.\n");

            found=1;
            break;
        }
    }
    if (found==0){
        printf("Student not found.\n");
    }
}