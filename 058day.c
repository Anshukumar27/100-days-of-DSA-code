#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* left;
    struct node* right;
};


struct node* createNode(int data) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}


int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}


struct node* buildTree(int preorder[], int inorder[], int start, int end, int* preIndex) {
    
    if (start > end)
        return NULL;

  
    int curr = preorder[*preIndex];
    (*preIndex)++;

    struct node* root = createNode(curr);

    if (start == end)
        return root;

    int index = search(inorder, start, end, curr);

    root->left = buildTree(preorder, inorder, start, index - 1, preIndex);
    root->right = buildTree(preorder, inorder, index + 1, end, preIndex);

    return root;
}

void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int preorder[n], inorder[n];

    printf("Enter preorder traversal:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }

    printf("Enter inorder traversal:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    int preIndex = 0;

    struct node* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);

    printf("Postorder traversal:\n");
    postorder(root);

    return 0;
}