#include <stdio.h>
#include "student.h"

int main(){
    Student students[100];
    int count = 0;

    loadStudents(students, &count);

    int choice;

    while(1){
        printf("\n==== Student Record Manager ====\n");
        printf("1. Add student\n");
        printf("2. Display students\n");
        printf("3. Exit\n");
        printf("4. Save students\n");
        printf("5. Search student\n");
        printf("6. Delete Student\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                if(count >= 100){
                    printf("Student storage is full.\n");
                    break;
                }

                printf("\nEnter the details of student %d\n", count + 1);

                addStudent(&students[count]);

                count++;

                printf("Student added successfully.\n");
                break;

            case 2:
                if(count == 0){
                    printf("No student available.\n");
                    break;
                }

                printf("\n==== Student Records ====\n");

                for(int i = 0; i < count; i++){
                    printf("\nStudent %d\n", i + 1);
                    printf("ID: %d\n", students[i].id);
                    printf("Name: %s\n", students[i].name);
                    printf("Age: %d\n", students[i].age);
                    printf("Marks: %.2f\n", students[i].marks);
                }
                break;

            case 3:
                printf("Program ended.\n");
                return 0;

            case 4:{
                FILE *fp;

                fp = fopen("student.data", "wb");

                if(fp == NULL){
                    printf("Could not open the file.\n");
                    return 1;
                }

                fwrite(students, sizeof(Student), count, fp);

                fclose(fp);

                printf("Students saved successfully.\n");
                break;
            }
            case 5:{
                int id;
                printf("Enter the id of the student.\n");
                scanf("%d",&id);
                searchStudent(students,count,id);
                break;
            }
            case 6:{
                int id;
                printf("Enter the id of the student to delete.\n");
                scanf("%d",&id);
                deleteStudent(students,&count,id);
                break;
            }

            default:
                printf("Invalid choice.\n");
        }
    }
}