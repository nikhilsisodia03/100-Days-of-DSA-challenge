#include <stdio.h>

int lowerBound(int* nums, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n; 
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int upperBound(int* nums, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, x;
    if (scanf("%d", &n) != 1) return 0;
    
    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    scanf("%d", &x);

    printf("%d %d\n", lowerBound(nums, n, x), upperBound(nums, n, x));

    return 0;
}
