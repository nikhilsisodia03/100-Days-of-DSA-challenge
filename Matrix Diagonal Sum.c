#include <stdio.h>

int main() {
    int m, n, i, j;
    long long sum = 0;

    if (scanf("%d %d", &m, &n) != 2) return 0;

    int matrix[m][n];

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int limit = (m < n) ? m : n;

    for (i = 0; i < limit; i++) {
        sum += matrix[i][i];
    }

    printf("%lld\n", sum);

    return 0;
}