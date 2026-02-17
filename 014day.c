// Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are
//  1 and all non-diagonal elements are 0.

#include <stdio.h>

#define MAX 100

int isIdentity(int matrix[MAX][MAX], int n) {
    int i, j;

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {

            if(i == j) {
                if(matrix[i][j] != 1)
                    return 0;
            }
            else {
                if(matrix[i][j] != 0)
                    return 0;
            }
        }
    }

    return 1;
}

int main() {
    int matrix[MAX][MAX];
    int n, i, j;

    printf("Enter order of square matrix: ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nEntered Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    if(isIdentity(matrix, n))
        printf("\nMatrix is an Identity Matrix\n");
    else
        printf("\nMatrix is NOT an Identity Matrix\n");

    return 0;
}
