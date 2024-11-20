#include <stdio.h>

// Recursive function to print elements of the array
void printArray(int arr[], int size) {
    // Base case: if size is 0, return (empty array)
    if (size == 0) {
        return;
    }

    // Print the first element
    printf("%d ", arr[0]);

    // Recursive case: print the rest of the array (call for the subarray)
    printArray(arr + 1, size - 1);
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array elements: ");
    printArray(arr, n);
    
    return 0;
}
