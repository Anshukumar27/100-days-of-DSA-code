// Remove duplictae from array

#include<stdio.h>
#define num 100

void main (){
    int arr[num],n,i,j;

    printf("Enter number of element:");
    scanf("%d",&n);
    

    printf("Enter element:\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    printf("The elemnts are:");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    for(i=0;i<n;i++){
        for(j=i +1;j<n;j++){
            if(arr[i]==arr[j]){
                for (int k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                n--;
                j--;
            }
        }
    }
    printf("\nArray after deleting duplicate:");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

}