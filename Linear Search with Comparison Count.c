#include <stdio.h>

int main() {
    int n, k, i;
    int found_index = -1;
    int comparisons = 0;

    if (scanf("%d", &n) != 1) return 0;

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    for (i = 0; i < n; i++) {
        comparisons++; 
        if (arr[i] == k) {
            found_index = i;
            break;
        }
    }

    if (found_index != -1) {
        printf("Found at index %d\n", found_index);
    } else {
        printf("Not Found\n");
    }
    printf("Comparisons = %d\n", comparisons);

    return 0;
}