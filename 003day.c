// search and comprision of array elements

#include <stdio.h>
#define num 100

void main(){
    int arr[num], n, i, j, flag=0, searchElement;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &searchElement);
    for(i=0; i<n; i++){
        if(arr[i] == searchElement){
            printf("Element %d found at index %d\n", searchElement, i);
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("Element %d not found in the array\n", searchElement);
    }
    
}