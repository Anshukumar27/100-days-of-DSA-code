// mwege two sorted list
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head1 = NULL, *head2 = NULL, *newnode, *temp;
    struct node *merged = NULL, *tail = NULL;
    int n1, n2, i;

   
    printf("Enter number of nodes for first sorted list: ");
    scanf("%d", &n1);

    for(i = 1; i <= n1; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head1 == NULL)
            head1 = temp = newnode;
        else {
            temp->next = newnode;
            temp = newnode;
        }
    }

   
    printf("\nFirst List:\n");
    temp = head1;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    
    printf("\nEnter number of nodes for second sorted list: ");
    scanf("%d", &n2);

    for(i = 1; i <= n2; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head2 == NULL)
            head2 = temp = newnode;
        else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    printf("\nSecond List:\n");
    temp = head2;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

   
    struct node *p1 = head1;
    struct node *p2 = head2;

    while(p1 != NULL && p2 != NULL) {
        if(p1->data <= p2->data) {
            newnode = p1;
            p1 = p1->next;
        } else {
            newnode = p2;
            p2 = p2->next;
        }

        if(merged == NULL)
            merged = tail = newnode;
        else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    if(p1 != NULL)
        tail->next = p1;
    if(p2 != NULL)
        tail->next = p2;

    printf("\nMerged Sorted List:\n");
    temp = merged;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");

    return 0;
}