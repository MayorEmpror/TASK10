#include <stdio.h>
#include <string.h>  // Include this header for strcspn function

// Define the structure to store employee details
struct Employee {
    int id;              // Employee ID
    char name[50];       // Name of the employee
    char department[50]; // Department name
    float salary;        // Employee salary
};

// Function to input employee data
void inputEmployeeData(struct Employee *emp) {
    printf("\nEnter employee details:\n");

    // Input employee ID
    printf("Employee ID: ");
    scanf("%d", &emp->id);

    // Input employee name
    printf("Name: ");
    getchar(); // To clear the newline character left by the previous input
    fgets(emp->name, sizeof(emp->name), stdin);
    emp->name[strcspn(emp->name, "\n")] = '\0'; // Remove newline character at the end of name

    // Input department name
    printf("Department: ");
    fgets(emp->department, sizeof(emp->department), stdin);
    emp->department[strcspn(emp->department, "\n")] = '\0'; // Remove newline character at the end of department

    // Input employee salary
    printf("Salary: ");
    scanf("%f", &emp->salary);
}

// Function to display employee data
void displayEmployeeData(struct Employee emp) {
    printf("\nEmployee ID: %d\n", emp.id);
    printf("Name: %s\n", emp.name);
    printf("Department: %s\n", emp.department);
    printf("Salary: %.2f\n", emp.salary);
}

int main() {
    int numEmployees;

    // Ask user for the number of employees
    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);

    // Declare an array of Employee structures
    struct Employee employees[numEmployees];

    // Input data for each employee
    for (int i = 0; i < numEmployees; i++) {
        printf("\nEmployee %d:\n", i + 1);
        inputEmployeeData(&employees[i]);
    }

    // Display the data for all employees
    printf("\nEmployee Information:\n");
    for (int i = 0; i < numEmployees; i++) {
        printf("\nEmployee %d Details:\n", i + 1);
        displayEmployeeData(employees[i]);
    }

    return 0;
}
