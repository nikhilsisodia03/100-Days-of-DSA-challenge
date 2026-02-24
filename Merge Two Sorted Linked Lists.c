#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insert(struct Node* head, int data) {
    if (head == NULL) return createNode(data);
    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = createNode(data);
    return head;
}

struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != NULL) tail->next = l1;
    else tail->next = l2;

    return dummy.next;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, m, val;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &val);
            head1 = insert(head1, val);
        }
    }

    if (scanf("%d", &m) == 1) {
        for (int i = 0; i < m; i++) {
            scanf("%d", &val);
            head2 = insert(head2, val);
        }
    }

    struct Node* mergedHead = mergeLists(head1, head2);
    printList(mergedHead);

    return 0;
}
