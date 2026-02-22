#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, value;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    temp = head;
    while (temp != NULL) {
        printf("%d%s", temp->data, (temp->next ? " " : ""));
        temp = temp->next;
    }
    printf("\n");

    return 0;
}
