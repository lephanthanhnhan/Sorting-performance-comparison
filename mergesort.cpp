#include "mergesort.h"

void merge(int arr[], int left, int mid, int right) {
    int left_size = mid - left + 1, right_size = right - mid;
    int* left_arr = new int[left_size]; int* right_arr = new int[right_size];

    for (int i = 0; i < left_size; i++) left_arr[i] = arr[left + i];
    for (int j = 0; j < right_size; j++) right_arr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < left_size && j < right_size) {
        if (left_arr[i] <= right_arr[j]) arr[k++] = left_arr[i++];
        else arr[k++] = right_arr[j++];
    }

    while (i < left_size) arr[k++] = left_arr[i++];
    while (j < right_size) arr[k++] = right_arr[j++];

    delete[] left_arr;
    delete[] right_arr;
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid); merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}