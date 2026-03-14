#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) {
    struct Node* temp = *top;
    int val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}

struct Queue {
    struct Node *front, *rear;
};

void enqueue(struct Queue* q, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

int dequeue(struct Queue* q) {
    struct Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return val;
}

void reverseQueue(struct Queue* q) {
    struct Node* stack = NULL;
    
    while (q->front != NULL) {
        push(&stack, dequeue(q));
    }
    
    while (stack != NULL) {
        enqueue(q, pop(&stack));
    }
}

int main() {
    int n, val;
    if (scanf("%d", &n) != 1) return 0;
    
    struct Queue q = {NULL, NULL};
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }
    
    reverseQueue(&q);
    
    while (q.front != NULL) {
        printf("%d ", dequeue(&q));
    }
    
    return 0;
}
