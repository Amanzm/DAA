#include <stdio.h>
#include <stdlib.h>

// Function to merge three sorted arrays
void mergeThree(int arr[], int left, int middle1, int middle2, int right) {
    int n1 = middle1 - left + 1;
    int n2 = middle2 - middle1;
    int n3 = right - middle2 + 1;

    int* L1 = (int*)malloc(n1 * sizeof(int));
    int* L2 = (int*)malloc(n2 * sizeof(int));
    int* L3 = (int*)malloc(n3 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L1[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        L2[i] = arr[middle1 + 1 + i];
    for (int i = 0; i < n3; i++)
        L3[i] = arr[middle2 + 1 + i];

    int i = 0, j = 0, k = 0;
    int idx = left;

    while (i < n1 && j < n2 && k < n3) {
        if (L1[i] <= L2[j] && L1[i] <= L3[k]) {
            arr[idx++] = L1[i++];
        } else if (L2[j] <= L1[i] && L2[j] <= L3[k]) {
            arr[idx++] = L2[j++];
        } else {
            arr[idx++] = L3[k++];
        }
    }

    while (i < n1) {
        arr[idx++] = L1[i++];
    }
    while (j < n2) {
        arr[idx++] = L2[j++];
    }
    while (k < n3) {
        arr[idx++] = L3[k++];
    }

    free(L1);
    free(L2);
    free(L3);
}

// Function to perform 3-way merge sort
void mergeSort3Way(int arr[], int left, int right) {
    if (left < right) {
        int middle1 = left + (right - left) / 3;
        int middle2 = left + 2 * (right - left) / 3;

        mergeSort3Way(arr, left, middle1);
        mergeSort3Way(arr, middle1 + 1, middle2);
        mergeSort3Way(arr, middle2 + 1, right);

        mergeThree(arr, left, middle1, middle2, right);
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

    int* arr = (int*)malloc(size * sizeof(int));

    for (int i = 0; i < size; i++) {
        fscanf(inputFile, "%d", &arr[i]);
    }

    mergeSort3Way(arr, 0, size - 1);

    for (int i = 0; i < size; i++) {
        fprintf(outputFile, "%d ", arr[i]);
    }

    fclose(inputFile);
    fclose(outputFile);

    free(arr);

    return 0;
}
