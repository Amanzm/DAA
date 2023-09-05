#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Define the structure for the maximum subarray
typedef struct Subarr {
    int sum;
    int l;
    int h;
} Subarr;

// Function to find the maximum subarray crossing the midpoint
struct Subarr Max_Crossing_Sub(int A[], int l, int m, int h) {
    int left_sum = INT_MIN, left;
    int sum = 0;
    for (int i = m; i >= l; i--) {
        sum += A[i];
        if (sum > left_sum) {
            left_sum = sum;
            left = i;
        }
    }
    int right_sum = INT_MIN, right;
    sum = 0;
    for (int i = m + 1; i <= h; i++) {
        sum += A[i];
        if (sum > right_sum) {
            right_sum = sum;
            right = i;
        }
    }
    struct Subarr result;
    result.sum = left_sum + right_sum;
    result.l = left;
    result.h = right;

    return result;
}

// Function to find the maximum subarray using divide and conquer
struct Subarr Max_Sum_Sub(int A[], int l, int h) {
    if (l == h) {
        struct Subarr res;
        res.sum = A[l];
        res.h = res.l = l;
        return res;
    }

    int m = (l + h) / 2;

    struct Subarr leftArr = Max_Sum_Sub(A, l, m);
    struct Subarr rightArr = Max_Sum_Sub(A, m + 1, h);
    struct Subarr crossArr = Max_Crossing_Sub(A, l, m, h);

    if (leftArr.sum >= rightArr.sum && leftArr.sum >= crossArr.sum)
        return leftArr;
    else if (rightArr.sum >= leftArr.sum && rightArr.sum >= crossArr.sum)
        return rightArr;
    else
        return crossArr;
}

int main() {
    FILE *inputFile = fopen("input7.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    int n;
    fscanf(inputFile, "%d", &n);

    // Dynamically allocate memory for the array
    int *A = (int *)malloc(n * sizeof(int));
    if (A == NULL) {
        printf("Memory allocation failed\n");
        fclose(inputFile);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fscanf(inputFile, "%d", &A[i]);
    }

    fclose(inputFile);

    struct Subarr result = Max_Sum_Sub(A, 0, n - 1);

    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file\n");
        free(A);
        return 1;
    }

    fprintf(outputFile, "Sum of Max Subarray is: %d\nStarting Index is: %d\nEnding Index is: %d\n", result.sum, result.l, result.h);
    fclose(outputFile);

    // Free dynamically allocated memory
    free(A);

    return 0;
}
