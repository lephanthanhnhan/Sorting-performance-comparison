#ifndef SORT_H
#define SORT_H

// Shaker Sort
void shakerSort(int a[], int n);
void shakerSort(int a[], int n, long long &comp);

// Binary Insertion Sort
void binaryInsertionSort(int a[], int n);
void binaryInsertionSort(int a[], int n, long long &comp);

// Flash Sort
void flashSort(int a[], int n);
void flashSort(int a[], int n, long long &comp);

// Selection Sort
void selectionSort(int a[], int n);
void selectionSort(int a[], int n, long long &comp);

// Shell Sort
void shellSort(int a[], int n);
void shellSort(int a[], int n, long long &comp);

// Quick Sort
void quickSort(int a[], int left, int right);
void quickSort(int a[], int left, int right, long long &comp);

// Bubble Sort
void bubbleSort(int a[], int n);
void bubbleSort(int a[], int n, long long &comp);

// Insertion Sort
void insertionSort(int a[], int n);
void insertionSort(int a[], int n, long long &comp);

// Counting Sort
void countingSort(int a[], int n);
void countingSort(int a[], int n, long long &comp);

// Merge Sort
void mergeSort(int a[], int left, int right);
void mergeSort(int a[], int left, int right, long long &comp);

// Heap Sort
void heapSort(int a[], int n);
void heapSort(int a[], int n, long long &comp);

// Radix Sort
void radixSort(int a[], int n);
void radixSort(int a[], int n, long long &comp);
#endif