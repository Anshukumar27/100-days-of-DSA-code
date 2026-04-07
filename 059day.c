#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int findIndex(int inorder[], int start, int end, int value) {
    for(int i = start; i <= end; i++) {
        if(inorder[i] == value)
            return i;
    }
    return -1;
}

struct Node* buildTree(int inorder[], int postorder[], int start, int end, int* postIndex) {
    if(start > end)
        return NULL;

    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct Node* root = createNode(rootVal);

    if(start == end)
        return root;

    int index = findIndex(inorder, start, end, rootVal);

    root->right = buildTree(inorder, postorder, index + 1, end, postIndex);
    root->left  = buildTree(inorder, postorder, start, index - 1, postIndex);

    return root;
}

void preorder(struct Node* root) {
    if(root == NULL)
        return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int inorder[n], postorder[n];

    printf("Enter inorder traversal:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    printf("Enter postorder traversal:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &postorder[i]);
    }

    int postIndex = n - 1;

    struct Node* root = buildTree(inorder, postorder, 0, n - 1, &postIndex);

    printf("Preorder traversal:\n");
    preorder(root);

    return 0;
}