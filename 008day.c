// Given integers a and b, compute a^b using recursion without using pow() function.


#include <stdio.h>

int power(int a, int b) {
    if (b == 0)
        return 1;          // base case
    else
        return a * power(a, b - 1);  // recursive call
}

int main() {
    int a, b;
    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);

    printf("%d^%d = %d", a, b, power(a, b));
    return 0;
}
