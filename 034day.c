#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

// Push operation
void push(int value)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = top;
    top = newnode;
}

// Pop operation
int pop()
{
    struct node *temp;
    int value;

    if(top == NULL)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    temp = top;
    value = temp->data;
    top = top->next;
    free(temp);

    return value;
}

int main()
{
    char postfix[100];
    int i, a, b, result;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for(i = 0; postfix[i] != '\0'; i++)
    {
        if(isdigit(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else
        {
            b = pop();
            a = pop();

            switch(postfix[i])
            {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
    }

    result = pop();

    printf("Result = %d", result);

    return 0;
}