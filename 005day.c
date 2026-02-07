// merge two array 

#include<stdio.h>
#define num 100

void main(){
    int arr1[num],arr2[num],arr3[num],n1,n2,i,temp,j;
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n1);
    printf("Enter the elements of the array:\n");
    for(i = 0; i < n1; i++){
        scanf("%d", &arr1[i]);
    }
    printf("The element is:");
    for(i = 0; i < n1; i++){
        printf("%d ", arr1[i]);
   }
    printf("\nEnter the number of elements in the second array: ");
    scanf("%d", &n2);
    printf("Enter the elements of the array:\n");
    for(i = 0; i < n2; i++){
        scanf("%d", &arr2[i]);
    }
     printf("The element is:");
    for(i = 0; i < n2; i++){
        printf("%d ", arr2[i]);
   }
   for(i=0;i<n1;i++){
    arr3[i] = arr1[i];
   }

   for(i=0;i<n2;i++){
    arr3[n1+i]=arr2[i];
   }
   int n = n1 + n2;
   for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr3[j] > arr3[j + 1]) {
                temp = arr3[j];
                arr3[j] = arr3[j + 1];
                arr3[j + 1] = temp;
            }
        }
    }
    printf("\nMerged array is:\n");
    for(i = 0; i < n1 + n2; i++) {
        printf("%d ", arr3[i]);
    }

}