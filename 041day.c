#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    
    temp->data = value;
    temp->next = NULL;

    if(front == NULL){
        front = rear = temp;
    }
    else{
        rear->next = temp;
        rear = temp;
    }
}

void dequeue(){
    if(front == NULL){
        printf("Queue is Empty\n");
        return;
    }

    struct node *temp = front;
    printf("Deleted element: %d\n", front->data);

    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
}

void display(){
    struct node *temp = front;

    if(front == NULL){
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    int n, value;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        enqueue(value);
    }

    display();

    printf("Performing Dequeue Operation...\n");
    dequeue();

    display();

    return 0;
}