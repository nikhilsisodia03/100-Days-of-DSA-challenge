#include <stdio.h>
#include <string.h>

#define MAX_CAPACITY 100000

int heap[MAX_CAPACITY];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int x) {
    if (size >= MAX_CAPACITY) return;
    
    heap[size] = x;
    int current = size;
    size++;
    
    while (current > 0) {
        int parent = (current - 1) / 2;
        if (heap[current] < heap[parent]) {
            swap(&heap[current], &heap[parent]);
            current = parent;
        } else {
            break;
        }
    }
}

int peek() {
    if (size <= 0) return -1;
    return heap[0];
}

int extractMin() {
    if (size <= 0) return -1;
    
    int minItem = heap[0];
    heap[0] = heap[size - 1];
    size--;
    
    int current = 0;
    while (1) {
        int left = 2 * current + 1;
        int right = 2 * current + 2;
        int smallest = current;
        
        if (left < size && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < size && heap[right] < heap[smallest]) {
            smallest = right;
        }
        
        if (smallest != current) {
            swap(&heap[current], &heap[smallest]);
            current = smallest;
        } else {
            break;
        }
    }
    
    return minItem;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    char op[20];
    int val;
    
    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            scanf("%d", &val);
            insert(val);
        } else if (strcmp(op, "extractMin") == 0) {
            printf("%d\n", extractMin());
        } else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }
    
    return 0;
}
