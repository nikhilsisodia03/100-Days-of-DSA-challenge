#include <stdio.h>
#include <stdlib.h>

int heap[1000];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int x) {
    heap[size] = x;
    int current = size;
    size++;

    while (current > 0 && heap[(current - 1) / 2] > heap[current]) {
        swap(&heap[current], &heap[(current - 1) / 2]);
        current = (current - 1) / 2;
    }
}

void delete() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    printf("%d\n", heap[0]);
    heap[0] = heap[size - 1];
    size--;

    int i = 0;
    while (1) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && heap[left] < heap[smallest]) smallest = left;
        if (right < size && heap[right] < heap[smallest]) smallest = right;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else {
            break;
        }
    }
}

void peek() {
    if (size == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", heap[0]);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        char op[10];
        scanf("%s", op);

        if (op[0] == 'i') { 
            int x;
            scanf("%d", &x);
            insert(x);
        } else if (op[0] == 'd') { 
            delete();
        } else if (op[0] == 'p') { 
            peek();
        }
    }
    return 0;
}
