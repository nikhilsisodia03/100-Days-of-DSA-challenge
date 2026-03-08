#include <stdio.h>
#include <stdlib.h>

struct CircularQueue {
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
};

void init(struct CircularQueue *q, int k) {
    q->arr = (int *)malloc(k * sizeof(int));
    q->capacity = k;
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

void enqueue(struct CircularQueue *q, int value) {
    if (q->size == q->capacity) return;
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = value;
    q->size++;
}

void dequeue(struct CircularQueue *q) {
    if (q->size == 0) return;
    q->front = (q->front + 1) % q->capacity;
    q->size--;
}

void display(struct CircularQueue *q) {
    for (int i = 0; i < q->size; i++) {
        int index = (q->front + i) % q->capacity;
        printf("%d%c", q->arr[index], (i == q->size - 1 ? '\n' : ' '));
    }
}

int main() {
    int n, m, val;
    struct CircularQueue q;

    if (scanf("%d", &n) != 1) return 0;
    init(&q, n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }

    if (scanf("%d", &m) != 1) return 0;
    for (int i = 0; i < m; i++) {
        dequeue(&q);
    }

    display(&q);

    free(q.arr);
    return 0;
}
