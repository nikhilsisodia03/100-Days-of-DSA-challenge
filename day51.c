#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* insert(struct Node* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

struct Node* findLCA(struct Node* root, int p, int q) {
    while (root != NULL) {
        if (p < root->data && q < root->data)
            root = root->left;
        else if (p > root->data && q > root->data)
            root = root->right;
        else
            return root;
    }
    return NULL;
}

int main() {
    int n, val, p, q;
    struct Node* root = NULL;

    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    scanf("%d %d", &p, &q);

    struct Node* lca = findLCA(root, p, q);
    if (lca != NULL) {
        printf("%d\n", lca->data);
    }

    return 0;
}
