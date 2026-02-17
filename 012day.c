// cheack symetric or not
#include <stdio.h>

int main() {
    int n, i, j;
    
    printf("Enter order of square matrix: ");
    scanf("%d", &n);

    int a[n][n],r,c;

    printf("Enter matrix elements:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            printf("%d", a[i][j]);
        }
    }

    printf(" Matrix is:");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", a[i][j]);
        
    }
}


    int symmetric = 1;  // assume symmetric

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(a[i][j] != a[j][i]) {
                symmetric = 0;
                break;
            }
        }
    }

    if(symmetric == 1)
        printf("Matrix is Symmetric\n");
    else
        printf("Matrix is Not Symmetric\n");

    return 0;
}
