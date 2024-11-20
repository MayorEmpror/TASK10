#include <stdio.h>
#include <string.h>

// Recursive function to reverse a string
void reverseString(char str[], int start, int end) {
    // Base case: if start >= end, return as the string is reversed
    if (start >= end) {
        return;
    }

    // Swap the characters at start and end
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    // Recursively reverse the substring excluding the swapped characters
    reverseString(str, start + 1, end - 1);
}

int main() {
    char str[100];

    // Get user input
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove the newline character from fgets
    str[strcspn(str, "\n")] = '\0';

    // Find the length of the string
    int length = strlen(str);

    // Call the recursive function to reverse the string
    reverseString(str, 0, length - 1);

    // Display the reversed string
    printf("Reversed string: %s\n", str);

    return 0;
}
