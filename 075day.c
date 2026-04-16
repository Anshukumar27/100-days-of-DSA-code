#include <stdio.h>

#define MAX 1000

int maxLen(int arr[], int n) {
    int prefixSum = 0;
    int maxLength = 0;

    int hash[2 * MAX];
    int index[2 * MAX];

    for (int i = 0; i < 2 * MAX; i++) {
        hash[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if (prefixSum == 0) {
            maxLength = i + 1;
        }

        int key = prefixSum + MAX;  

    
        if (hash[key] != -1) {
            int len = i - hash[key];
            if (len > maxLength) {
                maxLength = len;
            }
        } else {
            
            hash[key] = i;
        }
    }

    return maxLength;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", maxLen(arr, n));

    return 0;
}