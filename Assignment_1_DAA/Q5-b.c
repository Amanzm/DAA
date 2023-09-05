#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Function to find the ith order statistic (ith minimum) in the array
int quickSelect(int arr[], int low, int high, int i) {
    if (low == high)
        return arr[low];

    int pivotIndex = partition(arr, low, high);
    int k = pivotIndex - low + 1;

    if (i == k)
        return arr[pivotIndex];
    else if (i < k)
        return quickSelect(arr, low, pivotIndex - 1, i);
    else
        return quickSelect(arr, pivotIndex + 1, high, i - k);
}

int main() {
    FILE* inputFile = fopen("input7.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");

    if (!inputFile || !outputFile) {
        printf("File error.\n");
        return 1;
    }

    int size;
    fscanf(inputFile, "%d", &size);

    int* arr = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        fscanf(inputFile, "%d", &arr[i]);
    }

    int i;
    printf("Enter the value of i (1-based index): ");
    scanf("%d", &i);

    if (i >= 1 && i <= size) {
        int ithOrderStatistic = quickSelect(arr, 0, size - 1, i);
        printf("The %dth order statistic is: %d\n", i, ithOrderStatistic);
        fprintf(outputFile, "The %dth order statistic is: %d\n", i, ithOrderStatistic);
    } else {
        printf("Invalid value of i.\n");
    }

    fclose(inputFile);
    fclose(outputFile);

    free(arr);

    return 0;
}
