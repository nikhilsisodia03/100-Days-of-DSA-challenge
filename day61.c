#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, isDirected;
    
    scanf("%d %d", &n, &m);
    
    scanf("%d", &isDirected);

    int adj[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;

        if (!isDirected) {
            adj[v][u] = 1;
        }
    }

    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}
