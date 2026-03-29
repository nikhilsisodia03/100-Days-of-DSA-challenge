#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

struct TreeNode* newNode(int val) {
    if (val == -1) return NULL;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

void mirror(struct TreeNode* node) {
    if (node == NULL) return;
    struct TreeNode* temp = node->left;
    node->left = node->right;
    node->right = temp;
    mirror(node->left);
    mirror(node->right);
}

void printInorder(struct TreeNode* node) {
    if (node == NULL) return;
    printInorder(node->left);
    printf("%d ", node->val);
    printInorder(node->right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (n == 0 || arr[0] == -1) return 0;

    struct TreeNode* root = newNode(arr[0]);
    struct TreeNode** queue = (struct TreeNode**)malloc(n * sizeof(struct TreeNode*));
    int head = 0, tail = 0;
    queue[tail++] = root;

    int i = 1;
    while (i < n && head < tail) {
        struct TreeNode* curr = queue[head++];
        
        curr->left = newNode(arr[i++]);
        if (curr->left) queue[tail++] = curr->left;
        
        if (i < n) {
            curr->right = newNode(arr[i++]);
            if (curr->right) queue[tail++] = curr->right;
        }
    }

    mirror(root);
    printInorder(root);
    printf("\n");

    return 0;
}
