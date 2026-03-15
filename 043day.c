#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int value){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node* buildTree(int arr[], int n){
    if(n == 0) return NULL;

    struct node* root = newNode(arr[0]);
    struct node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    int i = 1;

    while(i < n){
        struct node* temp = queue[front++];

        if(i < n){
            temp->left = newNode(arr[i++]);
            queue[rear++] = temp->left;
        }

        if(i < n){
            temp->right = newNode(arr[i++]);
            queue[rear++] = temp->right;
        }
    }

    return root;
}

void inorder(struct node* root){
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main(){
    int n;

    printf("Enter number of nodes: ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter level order traversal:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    struct node* root = buildTree(arr,n);

    printf("Inorder Traversal of Tree:\n");
    inorder(root);

    return 0;
}