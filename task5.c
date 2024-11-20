#include <stdio.h>

// Recursive function to calculate the sum of digits of a number
int sumOfDigits(int n) {
    // Base case: if the number is 0, the sum is 0
    if (n == 0) {
        return 0;
    }
    
    // Recursive case: sum the last digit and the sum of remaining digits
    return n % 10 + sumOfDigits(n / 10);
}

int main() {
    int num;

    // Get user input
    printf("Enter a number: ");
    scanf("%d", &num);

    // Call the recursive function and display the result
    printf("The sum of digits is: %d\n", sumOfDigits(num));

    return 0;
}
