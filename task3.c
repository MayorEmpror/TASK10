#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CARS 1000
static int cars_count = 0;


struct Cars {
    char model[100];
    int year;
    float price;
};


void clear_input_buffer() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);  
}


void addCars(struct Cars shrm[], int i) {
    char string[100];
    printf("Enter model: ");
    fgets(string, 100, stdin);  
    string[strcspn(string, "\n")] = 0;  
    strcpy(shrm[i].model, string);

    printf("Enter year: ");
    scanf("%d", &shrm[i].year); 
    clear_input_buffer(); 

    printf("Enter price: ");
    scanf("%f", &shrm[i].price); 
    clear_input_buffer();  

    cars_count++; 
}


void display(struct Cars shrm[]) {
    if (cars_count == 0) {
        printf("No cars in the dealership.\n");
        return;
    }

    for (int i = 0; i < cars_count; i++) {  
        printf("\nModel: %s\n", shrm[i].model);
        printf("Year: %d\n", shrm[i].year);
        printf("Price: $%.2f\n", shrm[i].price);
    }
}

void search(struct Cars shrm[]){
    char name[100];
    if(cars_count==0){
        printf("No cars in the dealership. \n");
        return;
    }
    printf("Enter car model name ");
    fgets(name,100,stdin);
    name[strcspn(name,"\n")] = 0;
    for(int i = 0;i<=cars_count;i++){
        if(strcmp(shrm[i].model,name)==0){
            printf("match found \n");
            printf("\nModel: %s\n", shrm[i].model);
            printf("Year: %d\n", shrm[i].year);
            printf("Price: $%.2f\n", shrm[i].price);
            return;
        }else {
            printf("match not found ");
             return;
            }
    }
}
int main() {
    struct Cars show_room_db[MAX_CARS];
    int choice = 1;

    while (1) {
        printf("\nCar Dealership Menu:\n");
        printf("1. Add new car\n");
        printf("2. Display all cars\n");
        printf("3. Search cars by make or model\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_input_buffer();  

        switch (choice) {
            case 1:
                addCars(show_room_db, cars_count);
                break;
            case 2:
                display(show_room_db);
                break;
            case 3:
               search(show_room_db);
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
