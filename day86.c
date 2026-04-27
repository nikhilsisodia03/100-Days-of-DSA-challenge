#include <stdio.h>

int findSquareRoot(int n) {
    if (n < 2) {
        return n;
    }

    int left = 1;
    int right = n / 2;
    int result = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (mid <= n / mid) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        return 0;
    }

    if (n < 0) {
        return 0;
    }

    printf("%d\n", findSquareRoot(n));

    return 0;
}
