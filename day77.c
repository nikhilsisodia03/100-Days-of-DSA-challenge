#include <stdio.h>
#include <stdlib.h>

struct Node {
    int target;
    struct Node* next;
};

void add_edge(struct Node** adj, int u, int v) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->target = v;
    new_node->next = adj[u];
    adj[u] = new_node;
}

void dfs(int u, int* visited, struct Node** adj, int* count) {
    visited[u] = 1;
    (*count)++;
    struct Node* temp = adj[u];
    while (temp) {
        if (!visited[temp->target]) {
            dfs(temp->target, visited, adj, count);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Node** adj = (struct Node**)calloc(n + 1, sizeof(struct Node*));
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(adj, u, v);
        add_edge(adj, v, u);
    }

    if (n == 0) {
        printf("CONNECTED\n");
        return 0;
    }

    int* visited = (int*)calloc(n + 1, sizeof(int));
    int visited_count = 0;

    dfs(1, visited, adj, &visited_count);

    if (visited_count == n) {
        printf("CONNECTED\n");
    } else {
        printf("NOT CONNECTED\n");
    }

    return 0;
}
