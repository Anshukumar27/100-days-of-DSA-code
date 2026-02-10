//  check the number is plandrome using two pointer comparision

#include <stdio.h>
#include <string.h>

int main() {
    int num;
    char str[20];

    printf("Enter a number: ");
    scanf("%d", &num);

    sprintf(str, "%d", num);

    int left = 0;
    int right = strlen(str) - 1;
    int isPalindrome = 1;

    while (left < right) {
        if (str[left] != str[right]) {
            isPalindrome = 0;
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome)
        printf("Palindrome number\n");
    else
        printf("Not a palindrome number\n");

    return 0;
}
