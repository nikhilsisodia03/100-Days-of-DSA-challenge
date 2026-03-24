#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node* buildTree(int n, int nodes[]) {
    if (n == 0 || nodes[0] == -1) return NULL;

    struct Node* root = newNode(nodes[0]);
    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int head = 0, tail = 0;
    queue[tail++] = root;

    int i = 1;
    while (i < n && head < tail) {
        struct Node* curr = queue[head++];

        if (i < n) {
            curr->left = newNode(nodes[i++]);
            if (curr->left) queue[tail++] = curr->left;
        }
        if (i < n) {
            curr->right = newNode(nodes[i++]);
            if (curr->right) queue[tail++] = curr->right;
        }
    }
    free(queue);
    return root;
}

struct Node* findLCA(struct Node* root, int p, int q) {
    if (root == NULL) return NULL;
    if (root->data == p || root->data == q) return root;

    struct Node* leftLCA = findLCA(root->left, p, q);
    struct Node* rightLCA = findLCA(root->right, p, q);

    if (leftLCA && rightLCA) return root;
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int p_val, q_val;
    scanf("%d %d", &p_val, &q_val);

    struct Node* root = buildTree(n, arr);
    struct Node* lca = findLCA(root, p_val, q_val);

    if (lca) printf("%d\n", lca->data);

    free(arr);
    return 0;
}
