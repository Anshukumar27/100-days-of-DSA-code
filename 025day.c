// count Occurrences of an Element in Linked List
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *newnode, *temp;
    int n, i, key, count = 0, position = 1;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Creating Linked List
    for(i = 1; i <= n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL) {
            head = newnode;
        }
        else {
            temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    printf("Enter element to count: ");
    scanf("%d", &key);

    // Counting and printing occurrences
    temp = head;
    position = 1;

    while(temp != NULL) {
        if(temp->data == key) {
            count++;
            printf("Element found at position: %d\n", position);
        }
        temp = temp->next;
        position++;
    }

    if(count == 0) {
        printf("Element not found in the list.\n");
    } else {
        printf("Total occurrences of %d = %d\n", key, count);
    }

    return 0;
}