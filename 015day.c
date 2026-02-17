// Given a matrix, calculate the sum of its primary
//  diagonal elements. The primary diagonal
//  consists of elements where row index equals column index.

#include <stdio.h>

#define MAX 100

int main() {
    int matrix[MAX][MAX];
    int r, c, i, j;
    int sum = 0;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter matrix elements:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }


    if(r != c) {
        printf("Primary diagonal is defined only for square matrices.\n");
        return 0;
    }

    for(i = 0; i < r; i++) {
        sum += matrix[i][i];
    }

    printf("Sum of primary diagonal elements = %d\n", sum);

    return 0;
}
