#include <stdio.h>
#include <stdbool.h>

bool canPaint(int boards[], int n, int k, long long maxTime) {
    int paintersUsed = 1;
    long long currentBoardSum = 0;

    for (int i = 0; i < n; i++) {
        if (currentBoardSum + boards[i] <= maxTime) {
            currentBoardSum += boards[i];
        } else {
            paintersUsed++;
            currentBoardSum = boards[i];
            if (paintersUsed > k) {
                return false;
            }
        }
    }
    return true;
}

long long solve(int boards[], int n, int k) {
    long long low = 0;
    long long high = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > low) low = boards[i];
        high += boards[i];
    }

    long long result = high;
    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (canPaint(boards, n, k, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int boards[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
    }

    printf("%lld\n", solve(boards, n, k));

    return 0;
}
