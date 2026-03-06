
#include <stdio.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

int main()
{
    int choice, value, i;
    
    do
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(top == SIZE - 1)
                {
                    printf("Stack Overflow\n");
                }
                else
                {
                    printf("Enter value: ");
                    scanf("%d", &value);
                    top++;
                    stack[top] = value;
                }
                break;

            case 2:
                if(top == -1)
                {
                    printf("Stack Underflow\n");
                }
                else
                {
                    printf("Deleted element: %d\n", stack[top]);
                    top--;
                }
                break;

            case 3:
                if(top == -1)
                {
                    printf("Stack is empty\n");
                }
                else
                {
                    printf("Stack elements:\n");
                    i = top;
                    do
                    {
                        printf("%d\n", stack[i]);
                        i--;
                    } 
                    while(i >= 0);
                }
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } 
    while(choice != 4);

    return 0;
}