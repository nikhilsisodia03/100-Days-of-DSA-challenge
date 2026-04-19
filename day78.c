#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 2e9

typedef struct Node {
    int v, w;
    struct Node* next;
} Node;

typedef struct {
    int v, dist;
} HeapNode;

typedef struct {
    HeapNode* data;
    int size;
    int capacity;
} MinHeap;

Node* createNode(int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->v = v;
    newNode->w = w;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node** adj, int u, int v, int w) {
    Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;
}

MinHeap* createHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->data = (HeapNode*)malloc(sizeof(HeapNode) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void push(MinHeap* heap, int v, int dist) {
    heap->data[heap->size].v = v;
    heap->data[heap->size].dist = dist;
    int i = heap->size++;
    while (i != 0 && heap->data[i].dist < heap->data[(i - 1) / 2].dist) {
        swap(&heap->data[i], &heap->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

HeapNode pop(MinHeap* heap) {
    HeapNode root = heap->data[0];
    heap->data[0] = heap->data[--heap->size];
    int i = 0;
    while (2 * i + 1 < heap->size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = left;
        if (right < heap->size && heap->data[right].dist < heap->data[left].dist)
            smallest = right;
        if (heap->data[i].dist <= heap->data[smallest].dist) break;
        swap(&heap->data[i], &heap->data[smallest]);
        i = smallest;
    }
    return root;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    Node** adj = (Node**)calloc(n + 1, sizeof(Node*));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w);
        addEdge(adj, v, u, w);
    }

    bool* visited = (bool*)calloc(n + 1, sizeof(bool));
    MinHeap* heap = createHeap(m * 2 + 1);
    
    long long total_weight = 0;
    int nodes_included = 0;
    push(heap, 1, 0);

    while (heap->size > 0 && nodes_included < n) {
        HeapNode top = pop(heap);
        int u = top.v;
        int w = top.dist;

        if (visited[u]) continue;

        visited[u] = true;
        total_weight += w;
        nodes_included++;

        Node* curr = adj[u];
        while (curr) {
            if (!visited[curr->v]) {
                push(heap, curr->v, curr->w);
            }
            curr = curr->next;
        }
    }

    printf("%lld\n", total_weight);

    return 0;
}
