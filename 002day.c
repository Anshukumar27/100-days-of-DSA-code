#include<stdio.h>
#define num 100

void main(){
   int arr[num],i,n,pos;
    printf("Enter the number of elements in array: ");
    scanf("%d",&n);
    printf("Enter the elements in array: ");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("The elements in array are : ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    printf("\nEnter the position to delete the element: ");
    scanf("%d",&pos);

    for(i=pos-1;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    n--;

    printf("The new array after deletion is: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}