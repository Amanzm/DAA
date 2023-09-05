#include <stdio.h>
#include <stdlib.h>

// Function to perform a linear search
int linearSearch(int *arr, int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // Element found, return its index
        }
    }
    return -1; // Element not found
}

// Function to perform a binary search
int binarySearch(int *arr, int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid; // Element found, return its index
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Element not found
}

// Function to perform a ternary search
int ternarySearch(int *arr, int left, int right, int key) {
    if (left <= right) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == key) {
            return mid1; // Element found, return its index
        }
        if (arr[mid2] == key) {
            return mid2; // Element found, return its index
        }

        if (key < arr[mid1]) {
            return ternarySearch(arr, left, mid1 - 1, key);
        } else if (key > arr[mid2]) {
            return ternarySearch(arr, mid2 + 1, right, key);
        } else {
            return ternarySearch(arr, mid1 + 1, mid2 - 1, key);
        }
    }
    return -1; // Element not found
}

int main() {
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files.");
        return 1;
    }

    int n, key;
    fscanf(inputFile, "%d", &n); // Read the number of elements
    fscanf(inputFile, "%d", &key); // Read the key to search for

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fscanf(inputFile, "%d", &arr[i]); // Read the array elements
    }

    int linearResult = linearSearch(arr, n, key);
    int binaryResult = binarySearch(arr, n, key);
    int ternaryResult = ternarySearch(arr, 0, n - 1, key);

    if (linearResult != -1) {
        fprintf(outputFile, "Linear Search: Element found at index: %d\n", linearResult);
    } else {
        fprintf(outputFile, "Linear Search: Element not found\n");
    }

    if (binaryResult != -1) {
        fprintf(outputFile, "Binary Search: Element found at index: %d\n", binaryResult);
    } else {
        fprintf(outputFile, "Binary Search: Element not found\n");
    }

    if (ternaryResult != -1) {
        fprintf(outputFile, "Ternary Search: Element found at index: %d\n", ternaryResult);
    } else {
        fprintf(outputFile, "Ternary Search: Element not found\n");
    }

    free(arr); // Free dynamically allocated memory
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
