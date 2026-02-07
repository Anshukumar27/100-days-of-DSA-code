// Reverse an array

#include <stdio.h>
#define num 100

void main(){
    int arr[num], n, i, j, temp;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    // Reversing the array
    for(i = 0, j = n - 1; i < j; i++, j--){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    printf("Reversed array:\n");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}