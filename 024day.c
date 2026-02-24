// Delete First Occurrence of a Key - Implement using linked list with
//  dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *newnode, *temp, *prev;
    int n, i, key, found = 0;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

   
    for(i = 1; i <= n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head == NULL)
            head = temp = newnode;
        else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    
    printf("\nOriginal List:\n");
    temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    
    printf("\nEnter key to delete: ");
    scanf("%d", &key);

    temp = head;
    prev = NULL;

    
    if(temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        found = 1;
    }
    else {
        while(temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if(temp != NULL) {
            prev->next = temp->next;
            free(temp);
            found = 1;
        }
    }

    if(found)
        printf("\nFirst occurrence of %d deleted.\n", key);
    else
        printf("\nKey not found in list.\n");

    printf("\nUpdated List:\n");
    temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");

    return 0;
}
