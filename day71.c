#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY -1

typedef struct {
    int* table;
    int size;
} HashTable;

HashTable* createTable(int m) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    ht->size = m;
    ht->table = (int*)malloc(sizeof(int) * m);
    for (int i = 0; i < m; i++) {
        ht->table[i] = EMPTY;
    }
    return ht;
}

void insert(HashTable* ht, int key) {
    int m = ht->size;
    int h_k = key % m;
    for (int i = 0; i < m; i++) {
        int index = (h_k + i * i) % m;
        if (ht->table[index] == EMPTY) {
            ht->table[index] = key;
            return;
        }
    }
}

int search(HashTable* ht, int key) {
    int m = ht->size;
    int h_k = key % m;
    for (int i = 0; i < m; i++) {
        int index = (h_k + i * i) % m;
        if (ht->table[index] == key) {
            return 1;
        }
        if (ht->table[index] == EMPTY) {
            return 0;
        }
    }
    return 0;
}

int main() {
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) return 0;

    HashTable* ht = createTable(m);

    for (int j = 0; j < n; j++) {
        char op[10];
        int val;
        scanf("%s %d", op, &val);

        if (strcmp(op, "INSERT") == 0) {
            insert(ht, val);
        } else if (strcmp(op, "SEARCH") == 0) {
            if (search(ht, val)) {
                printf("FOUND\n");
            } else {
                printf("NOT FOUND\n");
            }
        }
    }

    free(ht->table);
    free(ht);
    return 0;
}
