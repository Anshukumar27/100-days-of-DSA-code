#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = 0;

void enqueue(int value) {
    int i;

    if(size == MAX) {
        printf("Queue Overflow\n");
        return;
    }

    
    for(i = size - 1; i >= 0 && pq[i] > value; i--) {
        pq[i + 1] = pq[i];
    }

    pq[i + 1] = value;
    size++;
}

void dequeue() {
    if(size == 0) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Removed element: %d\n", pq[0]);

    for(int i = 1; i < size; i++) {
        pq[i - 1] = pq[i];
    }

    size--;
}

void display() {
    if(size == 0) {
        printf("Queue is empty\n");
        return;
    }

    printf("Priority Queue: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", pq[i]);
    }
    printf("\n");
}

int main() {
    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    display();

    printf("Deleting highest priority element...\n");
    dequeue();

    display();

    return 0;
}