#include <stdio.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

int main()
{
    int n, m, i, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &value);
        top++;
        stack[top] = value;
    }

    printf("Enter number of pops: ");
    scanf("%d", &m);

    for(i = 0; i < m; i++)
    {
        if(top != -1)
            top--;
    }

    printf("Remaining stack elements (top to bottom): ");

    for(i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }

    return 0;
}