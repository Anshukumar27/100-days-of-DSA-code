// Matrix addtion

#include<stdio.h>
void inputMatrix(int a[10][10], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void displayMatrix(int a[10][10], int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void additionMatrix(int a[10][10], int b[10][10], int c[10][10],
                    int r1, int c1, int c2) {
    int i, j;
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
                c[i][j] = a[i][j] + b[i][j];
            }
        }
    }


int main() {
    int a[10][10], b[10][10], c[10][10];
    int r1, c1, r2, c2;

   
    printf("Enter rows of first matrix: ");
    scanf("%d", &r1);

    printf("Enter columns of first matrix: ");
    scanf("%d", &c1);

    printf("Enter elements of first matrix:\n");
    inputMatrix(a, r1, c1);

    printf("Matrix is:\n");
    displayMatrix(a, r1, c1);


     printf("Enter rows of second matrix: ");
    scanf("%d", &r2);

    printf("Enter columns of second matrix: ");
    scanf("%d", &c2);

    printf("Enter elements of second matrix:\n");
    inputMatrix(b, r2, c2);

    printf("Matrix is:\n");
    displayMatrix(b, r2, c2);


    additionMatrix(a, b, c, r1, c1, c2);

    printf("Addition of two matrices are:\n");
    displayMatrix(c, r1, c2);

    return 0;
}
