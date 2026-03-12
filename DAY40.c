#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    // Phase 1: Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Phase 2: Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]); // Move current root to end
        heapify(arr, i, 0);     // Restore max heap for remaining array
    }
}

int main() {
    int arr[] = {73, 74, 75, 71, 69, 72, 76, 73};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}
