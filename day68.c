 #include <stdio.h>
#include <stdlib.h>

struct Node {
    int dest;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adj;
};

struct Graph* createGraph(int V) {
    struct Graph* g = malloc(sizeof(struct Graph));
    g->V = V;
    g->adj = malloc(V * sizeof(struct Node*));
    for (int i = 0; i < V; i++) g->adj[i] = NULL;
    return g;
}

void addEdge(struct Graph* g, int u, int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->dest = v;
    newNode->next = g->adj[u];
    g->adj[u] = newNode;
}

void topoSort(struct Graph* g) {
    int* in_degree = calloc(g->V, sizeof(int));
    
    for (int i = 0; i < g->V; i++) {
        struct Node* temp = g->adj[i];
        while (temp) {
            in_degree[temp->dest]++;
            temp = temp->next;
        }
    }

    int* queue = malloc(g->V * sizeof(int));
    int head = 0, tail = 0;

    for (int i = 0; i < g->V; i++) {
        if (in_degree[i] == 0) queue[tail++] = i;
    }

    int count = 0;
    int* result = malloc(g->V * sizeof(int));

    while (head < tail) {
        int u = queue[head++];
        result[count++] = u;

        struct Node* temp = g->adj[u];
        while (temp) {
            int v = temp->dest;
            in_degree[v]--;
            if (in_degree[v] == 0) queue[tail++] = v;
            temp = temp->next;
        }
    }

    if (count != g->V) {
        printf("Cycle detected! No topological order.\n");
    } else {
        for (int i = 0; i < count; i++) printf("%d ", result[i]);
        printf("\n");
    }

    free(in_degree);
    free(queue);
    free(result);
}
