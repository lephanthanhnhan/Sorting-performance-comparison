#include "radixsort.h"

int getMaxValue(int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

void countingSort(int arr[], int size, int exponent) {
    const int base = 10; int freCnt[base] = {0};
    int* tmp = new int[size];

    for (int i = 0; i < size; i++) {
        int digit = (arr[i] / exponent) % base;
        freCnt[digit]++;
    }
    for (int i = 1; i < base; i++) freCnt[i] += freCnt[i - 1];

    for (int i = size - 1; i >= 0; i--) {
        int digit = (arr[i] / exponent) % base;
        tmp[--freCnt[digit]] = arr[i];
    }
    for (int i = 0; i < size; i++) arr[i] = tmp[i];

    delete[] tmp;
}

void radix_sort(int arr[], int size) {
    if (size <= 1) return;
    int maxValue = getMaxValue(arr, size);
    for (int exponent = 1; maxValue / exponent > 0; exponent *= 10) countingSort(arr, size, exponent);
}