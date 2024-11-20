#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define max_len 100

// Function to calculate the length of the string
int counter(char str[]) {
    int len = 0; // Initialize len to 0
    for (int i = 0; str[i] != '\0'; i++) {
        len++;
    }
    return len;
}

// Recursive function to reverse (or shuffle) the string
void shufler(char str[], char New_string[], int count, int length) {
    if (count < length) {
        // Reverse the string by copying characters in reverse order
        New_string[count] = str[length - count - 1]; // Index adjustment for 0-based indexing
        shufler(str, New_string, count + 1, length); // Recursive call
    }
    // When recursion ends, print the result
    if (count == length) {
        New_string[count] = '\0';  // Null-terminate the string
        printf("Changed string is: %s\n", New_string); // Print the shuffled string
    }
}

int main() {
    char string[max_len];
    
    // Get input from the user
    printf("Enter a sentence: ");
    fgets(string, max_len, stdin);
    
    // Remove the newline character from fgets input (if any)
    string[strcspn(string, "\n")] = '\0';

    int string_len = counter(string);  // Get the length of the string

    // Create a new string to store the shuffled (reversed) result
    char New_string[string_len + 1]; // +1 for the null terminator

    // Call the recursive function to reverse the string (shuffling it)
    shufler(string, New_string, 0, string_len);
    
    return 0;
}
