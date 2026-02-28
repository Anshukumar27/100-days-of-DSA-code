// Doubly Linked List Insertion and Traversal - Implement 
// using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

int main() {
    int n, i;
    struct node *head = NULL, *temp = NULL, *newnode;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    i = 1;

    if(n > 0) {
        do {
            newnode = (struct node*)malloc(sizeof(struct node));
            printf("Enter data for node %d: ", i);
            scanf("%d", &newnode->data);

            newnode->prev = NULL;
            newnode->next = NULL;

            if(head == NULL) {
                head = newnode;
                temp = newnode;
            } else {
                temp->next = newnode;
                newnode->prev = temp;
                temp = newnode;
            }

            i++;
        } while(i <= n);
    }

    
    printf("\nForward Traversal: ");
    temp = head;

    if(temp != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while(temp != NULL);
    }

    printf("\nBackward Traversal: ");

   
    if(head != NULL) {
        temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }

        do {
            printf("%d ", temp->data);
            temp = temp->prev;
        } while(temp != NULL);
    }

    return 0;
}