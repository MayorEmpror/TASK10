#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKINGS 100  // Maximum number of packages
static int no_bookings = 0;  // Current number of bookings

// Structure to store package information
struct Package {
    char name[100];     // Package name
    char dest[100];     // Destination
    int duration;       // Duration in days
    int cost;           // Cost of the package
    int seats;          // Number of available seats
};

// Array to store all the travel packages
struct Package bookings[MAX_BOOKINGS];

// Function to display all available travel packages
void displayPackages() {
    if (no_bookings == 0) {
        printf("No travel packages available.\n");
    } else {
        printf("\nAvailable Packages:\n");
        for (int i = 0; i < no_bookings; i++) {
            printf("Package Name: %s\n", bookings[i].name);
            printf("Destination: %s\n", bookings[i].dest);
            printf("Duration: %d days\n", bookings[i].duration);
            printf("Cost: $%d\n", bookings[i].cost);
            printf("Seats Available: %d\n\n", bookings[i].seats);
        }
    }
}

// Function to book a travel package
void bookPackage() {
    char pack_name[100];
    printf("Enter the package name to book: ");
    scanf("%s", pack_name);

    int found = 0;
    for (int i = 0; i < no_bookings; i++) {
        if (strcmp(bookings[i].name, pack_name) == 0) {
            found = 1;

            if (bookings[i].seats > 0) {
                bookings[i].seats--;
                printf("Booking successful! Remaining seats for %s: %d\n", bookings[i].name, bookings[i].seats);
            } else {
                printf("Sorry, no seats available for this package.\n");
            }
            break;
        }
    }

    if (!found) {
        printf("Package not found. Please check the package name and try again.\n");
    }
}

// Function to add a new package to the system
void addPackage() {
    if (no_bookings >= MAX_BOOKINGS) {
        printf("Cannot add more packages. Maximum limit reached.\n");
        return;
    }

    printf("Enter package details:\n");

    printf("Package Name: ");
    scanf("%s", bookings[no_bookings].name);

    printf("Destination: ");
    scanf("%s", bookings[no_bookings].dest);

    printf("Duration (in days): ");
    scanf("%d", &bookings[no_bookings].duration);

    printf("Cost ($): ");
    scanf("%d", &bookings[no_bookings].cost);

    printf("Number of Seats Available: ");
    scanf("%d", &bookings[no_bookings].seats);

    no_bookings++;
    printf("Package added successfully!\n");
}

// Main function
int main() {
    int choice;

    do {
        printf("\n1) Exit\n");
        printf("2) Book a travel\n");
        printf("3) Display available packages\n");
        printf("4) Add a new travel package\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Exiting the program.\n");
                break;

            case 2:
                bookPackage();  // Book a package
                break;

            case 3:
                displayPackages();  // Display available packages
                break;

            case 4:
                addPackage();  // Add a new package
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 1);

    return 0;
}
