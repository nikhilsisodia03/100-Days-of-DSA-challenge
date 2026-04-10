#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int node;
    int dist;
} HeapNode;

typedef struct {
    HeapNode* data;
    int size;
    int capacity;
} MinHeap;

MinHeap* createHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->data = (HeapNode*)malloc(capacity * sizeof(HeapNode));
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void push(MinHeap* heap, int node, int dist) {
    heap->data[heap->size].node = node;
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

void dijkstra(int n, int startNode, int adj[n+1][n+1], int weights[n+1][n+1], int degree[n+1]) {
    int dist[n + 1];
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
    dist[startNode] = 0;

    MinHeap* pq = createHeap(n * n);
    push(pq, startNode, 0);

    while (pq->size > 0) {
        HeapNode current = pop(pq);
        int u = current.node;
        int d = current.dist;

        if (d > dist[u]) continue;

        for (int i = 0; i < degree[u]; i++) {
            int v = adj[u][i];
            int w = weights[u][i];
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(pq, v, dist[v]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) printf("Node %d: Unreachable\n", i);
        else printf("Node %d: %d\n", i, dist[i]);
    }

    free(pq->data);
    free(pq);
}
