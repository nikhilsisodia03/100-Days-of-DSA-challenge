#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];
    int left, right;
    char temp;

    if (scanf("%s", str) != 1) return 0;

    left = 0;
    right = strlen(str) - 1;

    while (left < right) {
        temp = str[left];
        str[left] = str[right];
        str[right] = temp;
        left++;
        right--;
    }

    printf("%s\n", str);

    return 0;
}