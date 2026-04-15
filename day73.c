#include <stdio.h>
#include <string.h>

char findFirstNonRepeating(char* s) {
    int count[26] = {0};
    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
    }

    for (int i = 0; i < n; i++) {
        if (count[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    return '$';
}

int main() {
    char s[100001];
    if (scanf("%s", s) == 1) {
        printf("%c\n", findFirstNonRepeating(s));
    }
    return 0;
}
