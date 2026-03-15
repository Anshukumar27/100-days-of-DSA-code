#include <stdio.h>

#define MAX 100

int queue[MAX], stack[MAX];
int front = -1, rear = -1;
int top = -1;

void enqueue(int x){
    if(rear == MAX-1){
        printf("Queue Overflow\n");
        return;
    }

    if(front == -1)
        front = 0;

    queue[++rear] = x;
}

int dequeue(){
    if(front == -1 || front > rear){
        printf("Queue Underflow\n");
        return -1;
    }

    return queue[front++];
}

void push(int x){
    stack[++top] = x;
}

int pop(){
    return stack[top--];
}

void display(){
    printf("Queue elements: ");
    for(int i = front; i <= rear; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main(){
    int n,x;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        enqueue(x);
    }

  
    while(front <= rear){
        push(dequeue());
    }

    
    while(top != -1){
        enqueue(pop());
    }

    display();

    return 0;
}