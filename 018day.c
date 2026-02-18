// Given an array of integers, rotate the array to the right by k positions.


#include<stdio.h>
#define num 100

int main(){
    int arr[num], n, i, k, temp, j;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter value of k: ");
    scanf("%d", &k);

    k = k % n; 

    for(i = 0; i < k; i++){
        temp = arr[n-1];   

        for(j = n-1; j > 0; j--){
            arr[j] = arr[j-1];   
        }

        arr[0] = temp;   
    }

    printf("Array after rotation: ");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}
