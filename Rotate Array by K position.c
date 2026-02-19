#include <stdio.h>

int main() {
    int n, k;

    scanf("%d", &n);

    int arr[100], rotated[100];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &k);

    k = k % n;   // handle k > n

    for(int i = 0; i < n; i++)
        rotated[(i + n - k) % n] = arr[i];

    for(int i = 0; i < n; i++)
        printf("%d ", rotated[i]);

    return 0;
}