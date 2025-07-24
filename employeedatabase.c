#include <stdio.h>

#include <stdlib.h>

#include <string.h>

struct Employee{

    char Name[101]; //1 for first null character

    int EmployeeId;

    float Salary;

    char Deparment[51];

    int YearsofExp;

    float PerformScore;

};





void addEmployee(struct Employee *arr, int size){



printf("Enter name: ");

scanf(" %[^\n]", arr[size].Name);



 printf("Enter Employee ID: ");

scanf("%d", &arr[size].EmployeeId); 



printf("Enter Salary: ");

scanf("%f", &arr[size].Salary);



printf("Enter Department: ");

scanf(" %[^\n]", arr[size].Deparment);



printf("Enter Years of Experience: ");

scanf("%d", &arr[size].YearsofExp);



arr[size].PerformScore = (0.3*arr[size].YearsofExp) + (0.7*arr[size].Salary / 1000);



printf("Successfully added a new Employee.");



}





void updateEmployee(int searchedId,struct Employee *arr, int size){



int x = 0; //0 means id not found





for (int i = 0; i < size; i++) {

    if (arr[i].EmployeeId == searchedId) {

         

        x = 1;

         getchar();

         

         printf("Enter the new Department: ");

         scanf("%[^\n]", arr[i].Deparment); 

        

         printf("Enter the new Salary: ");

         scanf("%f", &arr[i].Salary);

        

 arr[i].PerformScore = (0.3*arr[i].YearsofExp) + (0.7*arr[i].Salary / 1000);

           printf("Successfully updated Employee.");

           

           

            break;

    }

}



if (x == 0){

     printf("Employee with ID %d not found.\n", searchedId);

}



}



void displayEmployees(struct Employee *arr, int size){



if (size == 0) {

    printf("No employees to display.\n");

    return;

}





 

for (int i = 0; i < size - 1; i++) {

    for (int j = 0; j < size - i - 1; j++) {

        if (arr[j].PerformScore < arr[j + 1].PerformScore) {

            // Swap the structs

            struct Employee temp = arr[j];

            arr[j] = arr[j + 1];

            arr[j + 1] = temp;

        }

    }

}



// Print table header

printf("\n%-20s %-12s %-10s %-15s %-10s %-15s\n", 

    "Name", "Employee ID", "Salary", "Department", "Experience", "Performance");

printf("---------------------------------------------------------------------------------------------\n");



// Print each employee's details

for (int i = 0; i < size; i++) {

    printf("%-20s %-12d %-10.2f %-15s %-10d %-15.2f\n",

        arr[i].Name,

        arr[i].EmployeeId,

        arr[i].Salary,

        arr[i].Deparment,

        arr[i].YearsofExp,

        arr[i].PerformScore

    );

}



}



void searchEmployeeByName(char searchedName[], struct Employee *arr, int size){

int x = 0; // 0 means name not found



for (int i = 0; i < size; i++) {

    if (strcmp(arr[i].Name, searchedName) == 0) {

        x = 1;



        printf("Employee found:\n");

        printf("Name: %s\n", arr[i].Name);

        printf("ID: %d\n", arr[i].EmployeeId);

        printf("Salary: %.2f\n", arr[i].Salary);

        printf("Department: %s\n", arr[i].Deparment);

        printf("Years of Experience: %d\n", arr[i].YearsofExp);

        printf("Performance Score: %.2f\n", arr[i].PerformScore);



        break;

    }

}



if (x == 0) {

    printf("Employee with name '%s' not found.\n", searchedName);

}



}





int main(){



int cap = 2;

int size = 0;



struct Employee *arr = malloc(cap * sizeof(struct Employee));

if (arr == NULL) {

    printf("Initial allocation failed.\n");

    return 1;

}





while (1){

int option;// this is the variable for the first set of choice option

printf("Employee Performance Management System\n");



printf("1. Add Employee\n");



printf("2. Update Employee\n");



printf("3. Display All Employees\n");



printf("4. Search Employee by Name \n");



printf("5. Exit\n");







 printf("Enter the number of your choice: ");



 scanf("%d", &option);







if(option >= 6 || option < 1){





 printf("You have selected an invalid option run the system again");



  exit (1);



}





//add Employee

else if(option == 1){



          if (size == cap) {

            cap *= 2;

            struct Employee *temp = realloc(arr, cap * sizeof(struct Employee));

            if (temp == NULL) {

                printf("Reallocation failed.\n");

                free(arr);

                return 1;

            }

            arr = temp;

        }



    

    addEmployee(arr, size);

    

    cap++;

    size++;

    

}



//Update employee

else if(option == 2){

    

    int searchedId;

    

    printf("Enter the Id of the Employee you wish to update: \n");

    scanf("%d", &searchedId);

    

    updateEmployee(searchedId,arr,size);

    

}



//display all employees

else if(option == 3){

    

    

    displayEmployees(arr,size);

    

}



else if(option == 4){

    char searchedName[101]; 

    

    printf("Enter the name of the Employee you wish to find: \n");

    scanf(" %[^\n]", searchedName);

    

     searchEmployeeByName(searchedName, arr, size);

}



//exit option 5

else if(option == 5){



    printf("Exiting System");



    exit (0);

    }





}









}








