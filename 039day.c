#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int value){
    int i = size;
    heap[i] = value;
    size++;

    while(i != 0 && heap[(i-1)/2] > heap[i]){
        swap(&heap[(i-1)/2], &heap[i]);
        i = (i-1)/2;
    }
}

void heapify(int i){
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < size && heap[left] < heap[smallest])
        smallest = left;

    if(right < size && heap[right] < heap[smallest])
        smallest = right;

    if(smallest != i){
        swap(&heap[i], &heap[smallest]);
        heapify(smallest);
    }
}

void deleteMin(){
    if(size == 0){
        printf("Heap is empty\n");
        return;
    }

    printf("Deleted element: %d\n", heap[0]);

    heap[0] = heap[size-1];
    size--;

    heapify(0);
}

void display(){
    printf("Heap elements: ");
    for(int i = 0; i < size; i++){
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main(){
    int n, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        insert(x);
    }

    display();

    deleteMin();

    display();

    return 0;
}