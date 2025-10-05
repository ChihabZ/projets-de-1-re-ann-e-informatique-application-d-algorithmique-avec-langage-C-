#include<stdio.h>
#include<stdlib.h>


 struct informations{

    char firstName[20]; 
    char lastName[20];
    int age;
   };


int main(int argc , char *argv[]){

    struct informations p;
    struct informations *ptr = &p;

    printf("Enter First Name: ");
    scanf("%s", ptr->firstName);

    printf("Enter Last Name: ");
    scanf("%s", ptr->lastName);

    printf("Enter Age: ");
    scanf("%d", &ptr->age);

    
    printf("\nMemory Addresses:\n");
    printf("Address of First Name: %p\n", &ptr->firstName);
    printf("Address of Last Name:  %p\n", &ptr->lastName);
    printf("Address of Age:        %p\n", &ptr->age);

    return 0;
}//done 