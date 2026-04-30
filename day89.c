#include <stdio.h>
#include <stdbool.h>

bool isValid(int arr[], int n, int m, int maxAllowed) {
    int students = 1;
    int currentPages = 0;

    for (int i = 0; i < n; i++) {
        if (currentPages + arr[i] <= maxAllowed) {
            currentPages += arr[i];
        } else {
            students++;
            currentPages = arr[i];
            if (students > m) {
                return false;
            }
        }
    }
    return true;
}

int allocateBooks(int arr[], int n, int m) {
    if (m > n) {
        return -1;
    }

    int low = 0;
    int high = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > low) {
            low = arr[i];
        }
        high += arr[i];
    }

    int result = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isValid(arr, n, m, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", allocateBooks(arr, n, m));

    return 0;
}
