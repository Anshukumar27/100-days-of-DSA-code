#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct node* insertEnd(struct node* head, int value) {
    struct node* newNode = createNode(value);
    
    if (head == NULL)
        return newNode;

    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

struct node* rotateRight(struct node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    struct node* temp = head;
    int count = 1;

    while (temp->next != NULL) {
        temp = temp->next;
        count++;
    }

    temp->next = head;

    k = k % count;
    int steps = count - k;

    struct node* newTail = head;

    for (int i = 1; i < steps; i++)
        newTail = newTail->next;

    struct node* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}

void display(struct node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;
    int n, value, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("Original List:\n");
    display(head);

    printf("Enter k: ");
    scanf("%d", &k);

    head = rotateRight(head, k);

    printf("Rotated List:\n");
    display(head);

    return 0;
}