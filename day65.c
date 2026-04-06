#include <stdbool.h>

bool dfs(int v, int parent, bool visited[], int V, int adj[V][V]) {
    visited[v] = true;

    for (int i = 0; i < V; i++) {
        if (adj[v][i]) {
            if (!visited[i]) {
                if (dfs(i, v, visited, V, adj))
                    return true;
            } else if (i != parent) {
                return true;
            }
        }
    }
    return false;
}

void isCycleDFS(int V, int adj[V][V]) {
    bool visited[V];

    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, V, adj)) {
                printf("YES\n");
                return;
            }
        }
    }

    printf("NO\n");
}
