// Write a C program to insert an element x at a given 1-based 
// position pos in an array of n integers. Shift existing elements 
// to the right to make space.

#include<stdio.h>
#define num 100
void main(){
    int arr[num], n, i, x, pos;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter element to insert: ");
    scanf("%d", &x);
    printf("Enter position to insert (1-based index): ");
    scanf("%d", &pos);
    
    // Shift elements to the right
    for(i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    
    // Insert the new element
    arr[pos - 1] = x;
    n++; // Increase the size of the array
    
    printf("Array after insertion:\n");
    for(i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
}