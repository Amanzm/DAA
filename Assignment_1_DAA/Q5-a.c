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

// Function to perform quicksort with the pivot at the last element and print intermediate steps
void quickSortLastAndPrint(int arr[], int low, int high, FILE* outputFile) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        fprintf(outputFile, "Pivot at index %d: ", pivotIndex);
        for (int i = low; i <= high; i++) {
            if (i == pivotIndex) {
                fprintf(outputFile, "[%d] ", arr[i]);
            } else {
                fprintf(outputFile, "%d ", arr[i]);
            }
        }
        fprintf(outputFile, "\n");

        quickSortLastAndPrint(arr, low, pivotIndex - 1, outputFile);
        quickSortLastAndPrint(arr, pivotIndex + 1, high, outputFile);
    }
}

// Function to perform quicksort with the pivot at the random element and print intermediate steps
void quickSortRandomAndPrint(int arr[], int low, int high, FILE* outputFile) {
    if (low < high) {
        // Choose a random pivot index
        srand(time(NULL));
        int pivotIndex = low + rand() % (high - low + 1);
        swap(&arr[pivotIndex], &arr[high]);

        int pivotIndexNew = partition(arr, low, high);
        fprintf(outputFile, "Pivot at index %d: ", pivotIndexNew);
        for (int i = low; i <= high; i++) {
            if (i == pivotIndexNew) {
                fprintf(outputFile, "[%d] ", arr[i]);
            } else {
                fprintf(outputFile, "%d ", arr[i]);
            }
        }
        fprintf(outputFile, "\n");

        quickSortRandomAndPrint(arr, low, pivotIndexNew - 1, outputFile);
        quickSortRandomAndPrint(arr, pivotIndexNew + 1, high, outputFile);
    }
}

// Function to perform quicksort with the pivot at the first element and print intermediate steps
void quickSortFirstAndPrint(int arr[], int low, int high, FILE* outputFile) {
    if (low < high) {
        int pivotIndex = low;
        int pivot = arr[pivotIndex];
        int i = low + 1;
        int j = high;

        while (1) {
            while (i <= j && arr[i] <= pivot) {
                i++;
            }
            while (arr[j] > pivot) {
                j--;
            }
            if (i <= j) {
                swap(&arr[i], &arr[j]);
            } else {
                break;
            }
        }

        swap(&arr[pivotIndex], &arr[j]);
        fprintf(outputFile, "Pivot at index %d: ", j);
        for (int i = low; i <= high; i++) {
            if (i == j) {
                fprintf(outputFile, "[%d] ", arr[i]);
            } else {
                fprintf(outputFile, "%d ", arr[i]);
            }
        }
        fprintf(outputFile, "\n");

        quickSortFirstAndPrint(arr, low, j - 1, outputFile);
        quickSortFirstAndPrint(arr, j + 1, high, outputFile);
    }
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

    int* arrLast = (int*)malloc(size * sizeof(int));
    int* arrRandom = (int*)malloc(size * sizeof(int));
    int* arrFirst = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        fscanf(inputFile, "%d", &arrLast[i]);
        arrRandom[i] = arrLast[i];
        arrFirst[i] = arrLast[i];
    }

    fprintf(outputFile, "Original Array: ");
    for (int i = 0; i < size; i++) {
        fprintf(outputFile, "%d ", arrLast[i]);
    }
    fprintf(outputFile, "\n\n");

    fprintf(outputFile, "Quicksort with Pivot at Last Element:\n");
    quickSortLastAndPrint(arrLast, 0, size - 1, outputFile);
    fprintf(outputFile, "\n");

    fprintf(outputFile, "Quicksort with Pivot at Random Element:\n");
    quickSortRandomAndPrint(arrRandom, 0, size - 1, outputFile);
    fprintf(outputFile, "\n");

    fprintf(outputFile, "Quicksort with Pivot at First Element:\n");
    quickSortFirstAndPrint(arrFirst, 0, size - 1, outputFile);
    fprintf(outputFile, "\n");

    fclose(inputFile);
    fclose(outputFile);

    free(arrLast);
    free(arrRandom);
    free(arrFirst);

    return 0;
}
