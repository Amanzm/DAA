#include <stdio.h>
#include <stdlib.h>


void matrix_multiply(int n, int A[n][n], int B[n][n], int C[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0; 
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}


void print_matrix_to_file(FILE *file, int n, int matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(file, "%d ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }
}

int main() {
    int n;
    printf("Enter the size of matrices (n): ");
    scanf("%d", &n);

    int A[n][n], B[n][n];


    FILE *input_file = fopen("input2.txt", "r");
    


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(input_file, "%d", &A[i][j]);
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(input_file, "%d", &B[i][j]);
        }
    }

    fclose(input_file);


    int C[n][n];


    matrix_multiply(n, A, B, C);


    FILE *output_file = fopen("output.txt", "w");
    

    print_matrix_to_file(output_file, n, C);

    fclose(output_file);



    return 0;
}
