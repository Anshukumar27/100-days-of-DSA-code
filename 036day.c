#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;

    if(front == NULL) {
        front = rear = temp;
        rear->next = front;   
    }
    else {
        rear->next = temp;
        rear = temp;
        rear->next = front;   
    }
}

void rotate() {
    if(front == NULL)
        return;

    front = front->next;
    rear = rear->next;
}

void display() {
    if(front == NULL)
        return;

    struct node *temp = front;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != front);
}

int main() {
    int n, m, i, x;

   
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for(i = 0; i < m; i++) {
        rotate();
    }

    display();

    return 0;
}