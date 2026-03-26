#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* left;
    struct node* right;
};


struct node* createNode(int data) {
    if (data == -1) return NULL;
    
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}


struct node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct node* root = createNode(arr[0]);

    struct node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct node* current = queue[front++];

      
        if (i < n && arr[i] != -1) {
            current->left = createNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;


        if (i < n && arr[i] != -1) {
            current->right = createNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    return root;
}

void zigzagTraversal(struct node* root) {
    if (!root) return;

    struct node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int leftToRight = 1;

    while (front < rear) {
        int size = rear - front;
        int level[1000];

        for (int i = 0; i < size; i++) {
            struct node* temp = queue[front++];

            int index = leftToRight ? i : size - 1 - i;
            level[index] = temp->data;

            if (temp->left) queue[rear++] = temp->left;
            if (temp->right) queue[rear++] = temp->right;
        }

        for (int i = 0; i < size; i++) {
            printf("%d ", level[i]);
        }

        leftToRight = !leftToRight;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct node* root = buildTree(arr, n);

    zigzagTraversal(root);

    return 0;
}