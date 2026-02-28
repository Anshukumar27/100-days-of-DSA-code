// Find Intersection Point of Two Linked Lists - Implement using linked 
// list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};


int length(struct node *head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}


struct node* findIntersection(struct node *head1, struct node *head2) {
    int len1 = length(head1);
    int len2 = length(head2);

    struct node *ptr1 = head1;
    struct node *ptr2 = head2;

    int diff;

    if(len1 > len2) {
        diff = len1 - len2;
        for(int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    } else {
        diff = len2 - len1;
        for(int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }

    while(ptr1 != NULL && ptr2 != NULL) {
        if(ptr1 == ptr2)
            return ptr1;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}

int main() {
    int n1, n2, i, pos;

    struct node *head1 = NULL, *head2 = NULL;
    struct node *temp = NULL, *newnode;

    
    printf("Enter number of nodes in first list: ");
    scanf("%d", &n1);

    for(i = 1; i <= n1; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head1 == NULL) {
            head1 = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

   
    printf("\nEnter number of nodes in second list: ");
    scanf("%d", &n2);

    for(i = 1; i <= n2; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if(head2 == NULL) {
            head2 = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }

    printf("\nEnter position in first list to create intersection (0 for no intersection): ");
    scanf("%d", &pos);

    if(pos > 0 && pos <= n1) {
        struct node *ptr1 = head1;
        for(i = 1; i < pos; i++)
            ptr1 = ptr1->next;

        temp->next = ptr1; 
    }

    struct node *result = findIntersection(head1, head2);

    if(result != NULL)
        printf("\nIntersection Point Data: %d\n", result->data);
    else
        printf("\nNo Intersection\n");

    return 0;
}