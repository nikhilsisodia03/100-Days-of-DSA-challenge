#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

void dfs(int u, struct Node** adj, int* visited, int* stack, int* stackIdx) {
    visited[u] = 1;
    
    struct Node* temp = adj[u];
    while (temp != NULL) {
        int v = temp->val;
        if (!visited[v]) {
            dfs(v, adj, visited, stack, stackIdx);
        }
        temp = temp->next;
    }
    
    stack[(*stackIdx)++] = u;
}

void topologicalSort(int numCourses, struct Node** adj) {
    int* visited = (int*)calloc(numCourses, sizeof(int));
    int* stack = (int*)malloc(numCourses * sizeof(int));
    int stackIdx = 0;

    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, stack, &stackIdx);
        }
    }

    printf("Topological Ordering: ");
    for (int i = stackIdx - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");

    free(visited);
    free(stack);
}

int main() {
    int numCourses = 4;
    struct Node** adj = (struct Node**)malloc(numCourses * sizeof(struct Node*));
    for (int i = 0; i < numCourses; i++) adj[i] = NULL;

    int edges[][2] = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    int numEdges = 4;

    for (int i = 0; i < numEdges; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->val = edges[i][1];
        newNode->next = adj[edges[i][0]];
        adj[edges[i][0]] = newNode;
    }

    topologicalSort(numCourses, adj);

    for (int i = 0; i < numCourses; i++) {
        struct Node* curr = adj[i];
        while (curr) {
            struct Node* nextNode = curr->next;
            free(curr);
            curr = nextNode;
        }
    }
    free(adj);

    return 0;
}
