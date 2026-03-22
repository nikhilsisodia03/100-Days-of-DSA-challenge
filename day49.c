#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }

    if (val > root->val) {
        root->right = insertIntoBST(root->right, val);
    } else {
        root->left = insertIntoBST(root->left, val);
    }

    return root;
}

void printInorder(struct TreeNode* root) {
    if (root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->val);
    printInorder(root->right);
}

int main() {
    struct TreeNode* root = NULL;

    root = insertIntoBST(root, 4);
    insertIntoBST(root, 2);
    insertIntoBST(root, 7);
    insertIntoBST(root, 1);
    insertIntoBST(root, 3);

    printf("BST before inserting 5 (Inorder): ");
    printInorder(root);
    printf("\n");

    root = insertIntoBST(root, 5);

    printf("BST after inserting 5 (Inorder):  ");
    printInorder(root);
    printf("\n");

    return 0;
}
