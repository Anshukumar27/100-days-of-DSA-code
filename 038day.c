#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1;
int rear = -1;

void push_front(int value){
    if(front == 0){
        printf("Deque Overflow\n");
    }
    else if(front == -1){
        front = rear = 0;
        deque[front] = value;
    }
    else{
        front--;
        deque[front] = value;
    }
}

void push_back(int value){
    if(rear == MAX-1){
        printf("Deque Overflow\n");
    }
    else if(front == -1){
        front = rear = 0;
        deque[rear] = value;
    }
    else{
        rear++;
        deque[rear] = value;
    }
}

void pop_front(){
    if(front == -1){
        printf("Deque Underflow\n");
    }
    else{
        printf("Removed: %d\n", deque[front]);
        if(front == rear)
            front = rear = -1;
        else
            front++;
    }
}

void pop_back(){
    if(rear == -1){
        printf("Deque Underflow\n");
    }
    else{
        printf("Removed: %d\n", deque[rear]);
        if(front == rear)
            front = rear = -1;
        else
            rear--;
    }
}

void display(){
    if(front == -1){
        printf("Deque is empty\n");
        return;
    }

    int i = front;
    printf("Deque elements: ");

    do{
        printf("%d ", deque[i]);
        i++;
    }while(i <= rear);

    printf("\n");
}

int main(){
    int choice, value;

    do{
        printf("\n1.Push Front\n2.Push Back\n3.Pop Front\n4.Pop Back\n5.Display\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter value: ");
                scanf("%d",&value);
                push_front(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d",&value);
                push_back(value);
                break;

            case 3:
                pop_front();
                break;

            case 4:
                pop_back();
                break;

            case 5:
                display();
                break;
        }

    }while(choice != 6);

    return 0;
}