#include <iostream>
#include <cmath>
#include <vector>
#include "sort.h"

using namespace std;

inline void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// SHAKER SORT

void shakerSort(int a[], int n)
{
    int left = 0;
    int right = n - 1;
    int k = 0;

    while (left < right)
    {
        for (int i = left; i < right; i++)
        {
            if (a[i] > a[i + 1])
            {
                Swap(a[i], a[i + 1]);
                k = i;
            }
        }
        right = k;

        for (int i = right; i > left; i--)
        {
            if (a[i] < a[i - 1])
            {
                Swap(a[i], a[i - 1]);
                k = i;
            }
        }
        left = k;
    }
}

void shakerSort(int a[], int n, long long &comp)
{
    int left = 0;
    int right = n - 1;
    int k = 0;

    while (left < right)
    {
        for (int i = left; i < right; i++)
        {
            comp++;
            if (a[i] > a[i + 1])
            {
                Swap(a[i], a[i + 1]);
                k = i;
            }
        }
        right = k;

        for (int i = right; i > left; i--)
        {
            comp++;
            if (a[i] < a[i - 1])
            {
                Swap(a[i], a[i - 1]);
                k = i;
            }
        }
        left = k;
    }
}

// BINARY INSERTION SORT

int binarySearch(int a[], int item, int left, int right)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (item < a[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }

    return left;
}

int binarySearchComp(int a[], int item, int left, int right, long long &comp)
{
    while (left <= right)
    {
        int mid = (left + right) / 2;

        comp++;
        if (item < a[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }

    return left;
}

void binaryInsertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int pos = binarySearch(a, key, 0, i - 1);

        for (int j = i - 1; j >= pos; j--)
        {
            a[j + 1] = a[j];
        }

        a[pos] = key;
    }
}

void binaryInsertionSort(int a[], int n, long long &comp)
{
    for (int i = 1; ++comp && i < n; i++)
    {
        int key = a[i];
        int pos = binarySearchComp(a, key, 0, i - 1, comp);

        for (int j = i - 1; j >= pos; j--)
        {
            a[j + 1] = a[j];
        }

        a[pos] = key;
    }
}

// FLASH SORT

void flashSort(int a[], int n)
{
    int m = int(0.45 * n);
    if (m <= 2)
        m = 2;

    int minVal = a[0];
    int maxIndex = 0;

    for (int i = 1; i < n; i++)
    {
        if (a[i] < minVal)
            minVal = a[i];
        if (a[i] > a[maxIndex])
            maxIndex = i;
    }

    if (a[maxIndex] == minVal)
        return;

    int *L = new int[m]();

    double c = (double)(m - 1) / (a[maxIndex] - minVal);

    for (int i = 0; i < n; i++)
    {
        int k = int(c * (a[i] - minVal));
        L[k]++;
    }

    for (int i = 1; i < m; i++)
        L[i] += L[i - 1];

    Swap(a[maxIndex], a[0]);

    int move = 0;
    int j = 0;
    int k = m - 1;

    while (move < n - 1)
    {
        while (j > L[k] - 1)
        {
            j++;
            if (j >= n)
            break;
            k = int(c * (a[j] - minVal));
        }

        int flash = a[j];

        while (j != L[k])
        {
            k = int(c * (flash - minVal));

            int temp = a[L[k] - 1];
            a[L[k] - 1] = flash;
            flash = temp;

            L[k]--;
            move++;
        }
    }

    delete[] L;

    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

void flashSort(int a[], int n, long long &comp)
{
    int m = int(0.45 * n);
    if (m <= 2) m = 2;

    int minVal = a[0];
    int maxIndex = 0;

    for (int i = 1; i < n; i++)
    {
        comp++;
        if (a[i] < minVal)
            minVal = a[i];

        comp++;
        if (a[i] > a[maxIndex])
            maxIndex = i;
    }

    if (a[maxIndex] == minVal)
        return;

    int *L = new int[m]();

    double c = (double)(m - 1) / (a[maxIndex] - minVal);

    for (int i = 0; i < n; i++)
    {
        int k = int(c * (a[i] - minVal));
        L[k]++;
    }

    for (int i = 1; i < m; i++)
        L[i] += L[i - 1];

    Swap(a[maxIndex], a[0]);

    int move = 0;
    int j = 0;
    int k = m - 1;

    while (move < n - 1)
    {
        while (j > L[k] - 1)
        {
            j++;
            k = int(c * (a[j] - minVal));
        }

        int flash = a[j];

        while (j != L[k])
        {
            k = int(c * (flash - minVal));

            int temp = a[L[k] - 1];
            a[L[k] - 1] = flash;
            flash = temp;

            L[k]--;
            move++;
        }
    }

    delete[] L;

    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0)
        {
            comp++;
            if (a[j] > key)
            {
                a[j + 1] = a[j];
                j--;
            }
            else
                break;
        }

        a[j + 1] = key;
    }
}


// SELECTION SORT

void selectionSort(int a[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for(int j = i + 1; j < n; j++)
        {
            if(a[j] < a[minIndex])
                minIndex = j;
        }

        if(minIndex != i)
            Swap(a[i], a[minIndex]);
    }
}

void selectionSort(int a[], int n, long long &comp)
{
    for(int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for(int j = i + 1; j < n; j++)
        {
            comp++;
            if(a[j] < a[minIndex])
                minIndex = j;
        }

        if(minIndex != i)
            Swap(a[i], a[minIndex]);
    }
}
// SHELL SORT
void shellSort(int a[], int n)
{
    for(int gap = n / 2; gap > 0; gap /= 2)
    {
        for(int i = gap; i < n; i++)
        {
            int temp = a[i];
            int j = i;

            while(j >= gap && a[j - gap] > temp)
            {
                a[j] = a[j - gap];
                j -= gap;
            }

            a[j] = temp;
        }
    }
}

void shellSort(int a[], int n, long long &comp)
{
    for(int gap = n / 2; gap > 0; gap /= 2)
    {
        for(int i = gap; i < n; i++)
        {
            int temp = a[i];
            int j = i;

            while(j >= gap)
            {
                comp++;
                if(a[j - gap] > temp)
                {
                    a[j] = a[j - gap];
                    j -= gap;
                }
                else
                    break;
            }

            a[j] = temp;
        }
    }
}
// QUICK SORT
void quickSort(int a[], int left, int right)
{
    int i = left;
    int j = right;
    int pivot = a[(left + right) / 2];

    while(i <= j)
    {
        while(a[i] < pivot) i++;
        while(a[j] > pivot) j--;

        if(i <= j)
        {
            Swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if(left < j)
        quickSort(a, left, j);

    if(i < right)
        quickSort(a, i, right);
}

void quickSort(int a[], int left, int right, long long &comp)
{
    int i = left;
    int j = right;
    int pivot = a[(left + right) / 2];

    while(i <= j)
    {
        while(true)
        {
            comp++;
            if(a[i] < pivot)
                i++;
            else
                break;
        }

        while(true)
        {
            comp++;
            if(a[j] > pivot)
                j--;
            else
                break;
        }

        if(i <= j)
        {
            Swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if(left < j)
        quickSort(a, left, j, comp);

    if(i < right)
        quickSort(a, i, right, comp);
}
// COUNTING SORT
void countingSort(int arr[], int n, long long &comp)
{
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        comp++;
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    vector<int> count(max + 1, 0);

    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    int index = 0;

    for (int i = 0; i <= max; i++)
    {
        while (count[i] > 0)
        {
            arr[index] = i;
            index++;
            count[i]--;
        }
    }
}
void countingSort(int arr[], int n)
{
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    vector<int> count(max + 1, 0);

    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    int index = 0;

    for (int i = 0; i <= max; i++)
    {
        while (count[i] > 0)
        {
            arr[index] = i;
            index++;
            count[i]--;
        }
    }
}
// BUBBLE SORT
void bubbleSort(int a[], int n, long long &comp)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            comp++;

            if (a[j] > a[j + 1])
            {
                Swap(a[j], a[j + 1]);
            }
        }
    }
}

void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                Swap(a[j], a[j + 1]);
            }
        }
    }
}
// INSERTION SORT
void insertionSort(int arr[], int n, long long &comp)
{
    for (int i = 1; i < n; i++)
    {
        int j = i;

        while (j > 0)
        {
            comp++;

            if (arr[j - 1] > arr[j])
            {
                Swap(arr[j - 1], arr[j]);
                j--;
            }
            else
                break;
        }
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i;

        while (j > 0)
        {
            if (arr[j - 1] > arr[j])
            {
                Swap(arr[j - 1], arr[j]);
                j--;
            }
            else
                break;
        }
    }
}

// MERGE SORT
void merge(int a[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = a[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    while (i < n1)
        a[k++] = L[i++];

    while (j < n2)
        a[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);

        merge(a, left, mid, right);
    }
}

void merge(int a[], int left, int mid, int right, long long &comp)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = a[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        comp++;

        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    while (i < n1)
        a[k++] = L[i++];

    while (j < n2)
        a[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(int a[], int left, int right, long long &comp)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(a, left, mid, comp);
        mergeSort(a, mid + 1, right, comp);

        merge(a, left, mid, right, comp);
    }
}
// HEAP SORT
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
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(A, n, i);

    int heap_size = n;

    for (int i = n - 1; i > 0; i--) {
        Swap(A[0], A[i]);
        heap_size--;
        maxHeapify(A, heap_size, 0);
    }
}

void maxHeapify(int A[], int heap_size, int i, long long &comp) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    if (l < heap_size) {
        comp++;
        if (A[l] > A[i])
            largest = l;
    }

    if (r < heap_size) {
        comp++;
        if (A[r] > A[largest])
            largest = r;
    }

    if (largest != i) {
        Swap(A[i], A[largest]);
        maxHeapify(A, heap_size, largest, comp);
    }
}

void heapSort(int* A, int n, long long &comp) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(A, n, i, comp);

    int heap_size = n;

    for (int i = n - 1; i > 0; i--) {
        Swap(A[0], A[i]);
        heap_size--;
        maxHeapify(A, heap_size, 0, comp);
    }
}

// RADIX SORT
int getMaxValue(int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}

int getMaxValue(int arr[], int size, long long &comp) {
    int maxVal = arr[0];

    for (int i = 1; i < size; i++) {
        comp++;
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    return maxVal;
}

void countingSortRadix(int arr[], int size, int exponent) {
    const int base = 10;
    int freCnt[base] = {0};
    int* tmp = new int[size];

    for (int i = 0; i < size; i++) {
        int digit = (arr[i] / exponent) % base;
        freCnt[digit]++;
    }

    for (int i = 1; i < base; i++)
        freCnt[i] += freCnt[i - 1];

    for (int i = size - 1; i >= 0; i--) {
        int digit = (arr[i] / exponent) % base;
        tmp[--freCnt[digit]] = arr[i];
    }

    for (int i = 0; i < size; i++)
        arr[i] = tmp[i];

    delete[] tmp;
}

void radixSort(int arr[], int size) {
    if (size <= 1) return;

    int maxValue = getMaxValue(arr, size);

    for (int exponent = 1; maxValue / exponent > 0; exponent *= 10)
        countingSortRadix(arr, size, exponent);
}

void radixSort(int arr[], int size, long long &comp) {
    if (size <= 1) return;

    int maxValue = getMaxValue(arr, size, comp);

    for (int exponent = 1; maxValue / exponent > 0; exponent *= 10)
        countingSortRadix(arr, size, exponent);
}