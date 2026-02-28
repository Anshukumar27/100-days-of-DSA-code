//  Circular Linked List Creation and Traversal - Implement
//  using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char name[50];
    struct node *next;
};

int main() {
    int n, i;
    struct node *head = NULL, *temp = NULL, *newnode;

    
    printf("Enter number of users: ");
    scanf("%d", &n);

    if(n <= 0) {
        printf("List is empty\n");
        return 0;
    }

   
    for(i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter name %d: ", i + 1);
        scanf("%s", newnode->name);   

        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    
    temp->next = head;

 
    printf("\nCircular Linked List (Names):\n");

    temp = head;
    do {
        printf("%s -> ", temp->name);
        temp = temp->next;
    } while(temp != head);

    printf("(back to %s)\n", head->name);

    return 0;
}