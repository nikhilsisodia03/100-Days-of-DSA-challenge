#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Graph {
    int V;
    int** adj;
    int* adjSize;
};

bool isCyclicUtil(int v, bool visited[], bool recStack[], struct Graph* graph) {
    if (visited[v] == false) {
        visited[v] = true;
        recStack[v] = true;

        for (int i = 0; i < graph->adjSize[v]; i++) {
            int neighbor = graph->adj[v][i];
            if (!visited[neighbor] && isCyclicUtil(neighbor, visited, recStack, graph)) {
                return true;
            } else if (recStack[neighbor]) {
                return true;
            }
        }
    }
    recStack[v] = false;
    return false;
}

bool isCyclic(struct Graph* graph) {
    bool* visited = (bool*)malloc(graph->V * sizeof(bool));
    bool* recStack = (bool*)malloc(graph->V * sizeof(bool));

    for (int i = 0; i < graph->V; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(i, visited, recStack, graph)) {
                free(visited);
                free(recStack);
                return true;
            }
        }
    }

    free(visited);
    free(recStack);
    return false;
}

int main() {
    int V = 4;
    struct Graph graph;
    graph.V = V;
    graph.adj = (int**)malloc(V * sizeof(int*));
    graph.adjSize = (int*)calloc(V, sizeof(int));

    graph.adj[0] = (int[]){1, 2}; graph.adjSize[0] = 2;
    graph.adj[1] = (int[]){2};    graph.adjSize[1] = 1;
    graph.adj[2] = (int[]){0, 3}; graph.adjSize[2] = 2;
    graph.adj[3] = (int[]){3};    graph.adjSize[3] = 1;

    if (isCyclic(&graph)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
