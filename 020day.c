// Given an array of integers, count the number of subarrays 
// whose sum is equal to zero.

#include<stdio.h>
#define num 1000

int main() {
    int arr[num], n, i;
    int prefix = 0, count = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int freq[2001] = {0};  
    int offset = 1000;  

    freq[offset] = 1; 

    for(i = 0; i < n; i++) {
        prefix += arr[i];

       
        count += freq[prefix + offset];

        freq[prefix + offset]++;
    }

    printf("Number of subarrays with sum 0 = %d", count);

    return 0;
}
