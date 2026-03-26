#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int n, int* arr) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node** queue = malloc(n * sizeof(struct Node*));
    int head = 0, tail = 0;
    queue[tail++] = root;
    int i = 1;
    while (i < n) {
        struct Node* curr = queue[head++];
        if (i < n) {
            curr->left = newNode(arr[i++]);
            if (curr->left) queue[tail++] = curr->left;
        }
        if (i < n) {
            curr->right = newNode(arr[i++]);
            if (curr->right) queue[tail++] = curr->right;
        }
    }
    free(queue);
    return root;
}

void zigzagTraversal(struct Node* root, int n) {
    if (!root) return;
    struct Node** queue = malloc(n * sizeof(struct Node*));
    int head = 0, tail = 0;
    queue[tail++] = root;
    bool leftToRight = true;
    while (head < tail) {
        int levelSize = tail - head;
        int* levelNodes = malloc(levelSize * sizeof(int));
        for (int i = 0; i < levelSize; i++) {
            struct Node* curr = queue[head++];
            int index = leftToRight ? i : (levelSize - 1 - i);
            levelNodes[index] = curr->data;
            if (curr->left) queue[tail++] = curr->left;
            if (curr->right) queue[tail++] = curr->right;
        }
        for (int i = 0; i < levelSize; i++) {
            printf("%d ", levelNodes[i]);
        }
        leftToRight = !leftToRight;
        free(levelNodes);
    }
    free(queue);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int* arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = buildTree(n, arr);
    zigzagTraversal(root, n);
    return 0;
}
