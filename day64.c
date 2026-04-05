#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void bfs(struct Graph* graph, int startVertex) {
    bool* visited = calloc(graph->numVertices, sizeof(bool));
    int* queue = malloc(graph->numVertices * sizeof(int));
    int head = 0, tail = 0;

    visited[startVertex] = true;
    queue[tail++] = startVertex;

    while (head < tail) {
        int currentVertex = queue[head++];
        printf("%d ", currentVertex);

        struct Node* temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue[tail++] = adjVertex;
            }
            temp = temp->next;
        }
    }

    free(visited);
    free(queue);
}
