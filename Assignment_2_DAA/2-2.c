#include <stdio.h>
#include <stdlib.h>

int findPeakEntry(int arr[], int n) {
   
    
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > arr[mid + 1]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
   
    FILE *fp = fopen("input.txt", "r");
  
    int n;
    fscanf(fp, "%d", &n);

    int *arr=(int *) malloc(sizeof(int) *n);
    
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }
    


    int peak_entry = findPeakEntry(arr, n);


    FILE *output = fopen("output.txt", "w");
    fprintf(output, "The peak entry is at position %d.\n", peak_entry + 1);
    fclose(output);

    return 0;
}

