#include "heapsort.h"
#include "DataGenerator.h"

void maxHeapify(int A[], int heap_size, int i) {
    int l = 2 * i + 1, r = 2 * i + 2, largest = i;

    if (l < heap_size && A[l] > A[i]) largest = l;
    if (r < heap_size && A[r] > A[largest]) largest = r;

    if (largest != i) {
        Swap(A[i], A[largest]);
        maxHeapify(A, heap_size, largest);
    }
}

void heapSort(int* A, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) maxHeapify(A, n, i);

    int heap_size = n;
    for (int i = n - 1; i > 0; i--) {
        Swap(A[0], A[i]);
        heap_size--;
        maxHeapify(A, heap_size, 0);
    }
}