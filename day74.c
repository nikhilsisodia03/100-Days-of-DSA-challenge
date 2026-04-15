#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    char **votes = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        votes[i] = (char *)malloc(101 * sizeof(char));
        scanf("%s", votes[i]);
    }

    qsort(votes, n, sizeof(char *), compare);

    char *winner = votes[0];
    int max_votes = 0;
    
    int current_votes = 1;
    for (int i = 1; i <= n; i++) {
        if (i < n && strcmp(votes[i], votes[i - 1]) == 0) {
            current_votes++;
        } else {
            if (current_votes > max_votes) {
                max_votes = current_votes;
                winner = votes[i - 1];
            }
            current_votes = 1;
        }
    }

    printf("%s %d\n", winner, max_votes);

    for (int i = 0; i < n; i++) {
        free(votes[i]);
    }
    free(votes);

    return 0;
}
