#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Deque {
    Node* front;
    Node* rear;
    int size;
} Deque;

Deque* createDeque() {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->front = dq->rear = NULL;
    dq->size = 0;
    return dq;
}

bool empty(Deque* dq) {
    return dq->size == 0;
}

void push_front(Deque* dq, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = dq->front;
    newNode->prev = NULL;
    if (empty(dq)) dq->rear = newNode;
    else dq->front->prev = newNode;
    dq->front = newNode;
    dq->size++;
}

void push_back(Deque* dq, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = dq->rear;
    newNode->next = NULL;
    if (empty(dq)) dq->front = newNode;
    else dq->rear->next = newNode;
    dq->rear = newNode;
    dq->size++;
}

int pop_front(Deque* dq) {
    if (empty(dq)) return -1;
    Node* temp = dq->front;
    int val = temp->data;
    dq->front = dq->front->next;
    if (dq->front == NULL) dq->rear = NULL;
    else dq->front->prev = NULL;
    free(temp);
    dq->size--;
    return val;
}

int pop_back(Deque* dq) {
    if (empty(dq)) return -1;
    Node* temp = dq->rear;
    int val = temp->data;
    dq->rear = dq->rear->prev;
    if (dq->rear == NULL) dq->front = NULL;
    else dq->rear->next = NULL;
    free(temp);
    dq->size--;
    return val;
}

int front(Deque* dq) {
    return empty(dq) ? -1 : dq->front->data;
}

int back(Deque* dq) {
    return empty(dq) ? -1 : dq->rear->data;
}

void clear(Deque* dq) {
    while (!empty(dq)) {
        pop_front(dq);
    }
}
