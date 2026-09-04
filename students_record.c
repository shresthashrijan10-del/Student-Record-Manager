#include <stdio.h>
typedef struct{
    int id;
    char name[50];
    int age;
    float marks;
}Student;

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

int main(){
    Student students[100];
    int count=0;
    int choice;
    while(1){
        printf("\n==== Student Record Manager ====\n");
        printf("1. Add student\n");
        printf("2. Display students\n");
        printf("3. Exit\n");
        printf("Choose\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            if(count>=100){
                printf("Student storage is full.\n");
                break;
            }
            printf("\nEnter the details of student %d\n",count+1);
            addStudent(&students[count]);
            count++;

            printf("Student added successfully.\n");
            break;
            
            case 2:
            if(count==0){
                printf("No student available.\n");
                break;
            }
            printf("\n==== Student Records ====\n");
            for(int i=0;i<count;i++){
                printf("\nStudent %d\n",i+1);
                printf("ID: %d\n",students[i].id);
                printf("Name: %s\n",students[i].name);
                printf("Age: %d\n",students[i].age);
                printf("Marks: %.2f\n",students[i].marks);
            }
            break;
            case 3:
            printf("Program ended.\n");
            return 0;
            default:
            printf("Invalid choice.\n");
        }
    }
}