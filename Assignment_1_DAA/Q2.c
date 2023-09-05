#include <stdio.h>
#include <stdlib.h>

// Function to read input from a file
void readInputFromFile(const char* filename, int** arr, int* size) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    fscanf(file, "%d", size);
    *arr = (int*)malloc(*size * sizeof(int));

    if (*arr == NULL) {
        printf("Memory allocation failed.\n");
        fclose(file);
        exit(1);
    }

    for (int i = 0; i < *size; i++) {
        fscanf(file, "%d", &(*arr)[i]);
    }

    fclose(file);
}

// Function to write output to a file
void writeOutputToFile(const char* filename, int* arr, int size) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);
}

// Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Insertion Sort
void insertionSort(int arr[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Heap Sort
void heapify(int arr[], int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    for (int i = size - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

// Bubble Sort
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void selectionSort(int arr[], int size) {
    int minIndex, temp;
    for (int i = 0; i < size - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Counting Sort
void countingSort(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    int* count = (int*)malloc((max + 1) * sizeof(int));
    int* output = (int*)malloc(size * sizeof(int));

    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }

    free(count);
    free(output);
}

// Bucket Sort
void bucketSort(int arr[], int size) {
    const int max = size;
    const int numBuckets = 10;
    int buckets[numBuckets][max + 1];
    int bucketSizes[numBuckets];
    int maxValue = arr[0];
    int minValue = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > maxValue)
            maxValue = arr[i];
        if (arr[i] < minValue)
            minValue = arr[i];
    }

    for (int i = 0; i < numBuckets; i++) {
        bucketSizes[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        int bucketIndex = (numBuckets * (arr[i] - minValue)) / (maxValue - minValue + 1);
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        insertionSort(buckets[i], bucketSizes[i]);
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    int* arr = NULL;
    int size;

    readInputFromFile("input7.txt", &arr, &size);

    printf("Sorting Algorithms Menu:\n");
    printf("1. Merge Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Heap Sort\n");
    printf("4. Bubble Sort\n");
    printf("5. Selection Sort\n");
    printf("6. Counting Sort\n");
    printf("7. Bucket Sort\n");
    printf("Enter your choice (1-7): ");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            mergeSort(arr, 0, size - 1);
            break;
        case 2:
            insertionSort(arr, size);
            break;
        case 3:
            heapSort(arr, size);
            break;
        case 4:
            bubbleSort(arr, size);
            break;
        case 5:
            selectionSort(arr, size);
            break;
        case 6:
            countingSort(arr, size);
            break;
        case 7:
            bucketSort(arr, size);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }

    writeOutputToFile("output.txt", arr, size);

    printf("Sorted array written to output.txt\n");

    // Free dynamically allocated memory
    free(arr);

    return 0;
}
