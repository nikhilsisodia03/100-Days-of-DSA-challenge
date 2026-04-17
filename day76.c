#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int dest;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
    bool* visited;
};

struct Node* createNode(int d) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->dest = d;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc((vertices + 1) * sizeof(struct Node*));
    graph->visited = malloc((vertices + 1) * sizeof(bool));

    for (int i = 0; i <= vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
    }
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void dfs(struct Graph* graph, int vertex) {
    graph->visited[vertex] = true;
    struct Node* temp = graph->adjLists[vertex];

    while (temp) {
        int connectedVertex = temp->dest;
        if (!graph->visited[connectedVertex]) {
            dfs(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    struct Graph* graph = createGraph(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!graph->visited[i]) {
            count++;
            dfs(graph, i);
        }
    }

    printf("%d\n", count);

    return 0;
}
