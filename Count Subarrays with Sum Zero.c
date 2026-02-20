#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long key;
    int count;
} HashEntry;

typedef struct {
    HashEntry* table;
    int size;
} HashTable;

int hash(long long key, int size) {
    int h = key % size;
    return h < 0 ? h + size : h;
}

void insert(HashTable* ht, long long key) {
    int h = hash(key, ht->size);
    while (ht->table[h].count != 0 && ht->table[h].key != key) {
        h = (h + 1) % ht->size;
    }
    ht->table[h].key = key;
    ht->table[h].count++;
}

int getCount(HashTable* ht, long long key) {
    int h = hash(key, ht->size);
    while (ht->table[h].count != 0) {
        if (ht->table[h].key == key) return ht->table[h].count;
        h = (h + 1) % ht->size;
    }
    return 0;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    long long current_sum = 0;
    long long zero_sum_count = 0;
    
    int table_size = n * 2;
    HashTable ht;
    ht.size = table_size;
    ht.table = (HashEntry*)calloc(table_size, sizeof(HashEntry));

    insert(&ht, 0);

    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        current_sum += val;

        int prev_occurrences = getCount(&ht, current_sum);
        zero_sum_count += prev_occurrences;
        
        insert(&ht, current_sum);
    }

    printf("%lld\n", zero_sum_count);

    free(ht.table);
    return 0;
}
