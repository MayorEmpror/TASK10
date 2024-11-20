#include <stdio.h>

// Recursive function to perform bubble sort
void bubbleSort(int arr[], int n) {
    // Base case: if the size of the array is 1, it's already sorted
    if (n == 1) {
        return;
    }

    // One pass through the array, compare and swap adjacent elements
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            // Swap arr[i] and arr[i+1]
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }

    // Recursively call bubbleSort for the first n-1 elements (ignore the last element as it's sorted)
    bubbleSort(arr, n - 1);
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Call the recursive bubbleSort function
    bubbleSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
