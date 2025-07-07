#include <stdio.h>

// Bubble Sort function
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        // Last i elements are already in place
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Iterative Binary Search function
int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid; // Found
        else if (arr[mid] < target)
            low = mid + 1; // Search right half
        else
            high = mid - 1; // Search left half
    }

    return -1; // Not found
}

int main() {
    int arr[] = {21, 10, 30, 4, 18, 2, 7, 14}; // Unsorted array
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 14;

    printf("Original array:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Sort the array first
    bubbleSort(arr, size);

    printf("Sorted array:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Now perform binary search
    int result = binarySearch(arr, size, target);

    if (result != -1)
        printf("Element %d found at index %d.\n", target, result);
    else
        printf("Element %d not found in the array.\n", target);

    return 0;
}
