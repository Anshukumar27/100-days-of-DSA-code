// Given an array of integers, find two elements whose sum is closest to zero.

#include<stdio.h>
#include<stdlib.h>
#define num 100

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main (){
    int arr[num], n, i;

    printf("Enter number of element: ");
    scanf("%d", &n);

    if(n < 2){
        printf("Need at least two elements.");
        return 0;
    }

    printf("Enter element: ");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Elements are: ");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    int minSum = arr[left] + arr[right];
    int bestL = left, bestR = right;

   
    while(left < right){
        int sum = arr[left] + arr[right];

        if(abs(sum) < abs(minSum)){
            minSum = sum;
            bestL = left;
            bestR = right;
        }

        if(sum < 0)
            left++;
        else
            right--;
    }

    printf("\nPair closest to zero: %d and %d", arr[bestL], arr[bestR]);
    printf("\nSum = %d", minSum);

    return 0;
}