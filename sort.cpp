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

    comp++; // while check
    while (left < right)
    {
        int i = left;
        comp++; // for check
        while (i < right)
        {
            comp++; // if (a[i] > a[i+1])
            if (a[i] > a[i + 1])
            {
                Swap(a[i], a[i + 1]);
                k = i;
            }
            i++;
            comp++; // for check lại
        }
        right = k;

        i = right;
        comp++; // for check
        while (i > left)
        {
            comp++; // if (a[i] < a[i-1])
            if (a[i] < a[i - 1])
            {
                Swap(a[i], a[i - 1]);
                k = i;
            }
            i--;
            comp++; // for check lại
        }
        left = k;

        comp++; // while check lại
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
    comp++; // while check lần đầu
    while (left <= right)
    {
        int mid = (left + right) / 2;

        comp++; // if (item < a[mid])
        if (item < a[mid])
            right = mid - 1;
        else
            left = mid + 1;

        comp++; // while check lại
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
    int i = 1;

    comp++; // check for (i < n)
    while (i < n)
    {
        int key = a[i];
        int pos = binarySearchComp(a, key, 0, i - 1, comp);

        int j = i - 1;

        comp++; // check j >= pos
        while (j >= pos)
        {
            a[j + 1] = a[j];
            j--;
            comp++; // check lại
        }

        a[pos] = key;

        i++;
        comp++; // check lại i < n
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
    comp++;
    if (m <= 2)
        m = 2;

    int minVal = a[0];
    int maxIndex = 0;

    int i = 1;
    comp++; // for check
    while (i < n)
    {
        comp++; // if (a[i] < minVal)
        if (a[i] < minVal)
            minVal = a[i];

        comp++; // if (a[i] > a[maxIndex])
        if (a[i] > a[maxIndex])
            maxIndex = i;

        i++;
        comp++; // for check lại
    }

    comp++; // if (a[maxIndex] == minVal)
    if (a[maxIndex] == minVal)
        return;

    int *L = new int[m]();

    double c = (double)(m - 1) / (a[maxIndex] - minVal);

    i = 0;
    comp++; // for check
    while (i < n)
    {
        int k = int(c * (a[i] - minVal));
        L[k]++;
        i++;
        comp++; // check lại
    }

    i = 1;
    comp++; // for check
    while (i < m)
    {
        L[i] += L[i - 1];
        i++;
        comp++; // check lại
    }

    Swap(a[maxIndex], a[0]);

    int move = 0;
    int j = 0;
    int k = m - 1;

    comp++; // while check
    while (move < n - 1)
    {
        comp++; // while (j > L[k] - 1)
        while (j > L[k] - 1)
        {
            j++;
            k = int(c * (a[j] - minVal));
            comp++; // check lại
        }

        int flash = a[j];

        comp++; // while (j != L[k])
        while (j != L[k])
        {
            k = int(c * (flash - minVal));

            int temp = a[L[k] - 1];
            a[L[k] - 1] = flash;
            flash = temp;

            L[k]--;
            move++;

            comp++; // check lại
        }

        comp++; // while check lại
    }

    delete[] L;

    i = 1;
    comp++; // for check
    while (i < n)
    {
        int key = a[i];
        int j = i - 1;

        comp++; // while check
        while (j >= 0)
        {
            comp++; // if (a[j] > key)
            if (a[j] > key)
            {
                a[j + 1] = a[j];
                j--;
            }
            else
                break;

            comp++; // while check lại
        }

        a[j + 1] = key;

        i++;
        comp++; // for check lại
    }
}
// SELECTION SORT

void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[minIndex])
                minIndex = j;
        }

        if (minIndex != i)
            Swap(a[i], a[minIndex]);
    }
}

void selectionSort(int a[], int n, long long &comp)
{
    int i = 0;

    comp++; // check i < n-1
    while (i < n - 1)
    {
        int minIndex = i;

        int j = i + 1;
        comp++; // check j < n
        while (j < n)
        {
            comp++; // if (a[j] < a[minIndex])
            if (a[j] < a[minIndex])
                minIndex = j;

            j++;
            comp++; // check lại j < n
        }

        comp++; // if (minIndex != i)
        if (minIndex != i)
            Swap(a[i], a[minIndex]);

        i++;
        comp++; // check lại i < n-1
    }
}
// SHELL SORT
void shellSort(int a[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = a[i];
            int j = i;

            while (j >= gap && a[j - gap] > temp)
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
    int gap = n / 2;

    comp++; // check gap > 0
    while (gap > 0)
    {
        int i = gap;

        comp++; // check i < n
        while (i < n)
        {
            int temp = a[i];
            int j = i;

            comp++; // check j >= gap
            while (j >= gap)
            {
                comp++; // if (a[j-gap] > temp)
                if (a[j - gap] > temp)
                {
                    a[j] = a[j - gap];
                    j -= gap;
                }
                else
                    break;

                comp++; // check lại j >= gap
            }

            a[j] = temp;

            i++;
            comp++; // check lại i < n
        }

        gap /= 2;
        comp++; // check lại gap > 0
    }
}
// QUICK SORT
void quickSort(int a[], int left, int right)
{
    int i = left;
    int j = right;
    int pivot = a[(left + right) / 2];

    while (i <= j)
    {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;

        if (i <= j)
        {
            Swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (left < j)
        quickSort(a, left, j);

    if (i < right)
        quickSort(a, i, right);
}

void quickSort(int a[], int left, int right, long long &comp)
{
    int i = left;
    int j = right;
    int pivot = a[(left + right) / 2];

    comp++; // while (i <= j)
    while (i <= j)
    {
        while (true)
        {
            comp++; // if (a[i] < pivot)
            if (a[i] < pivot)
                i++;
            else
                break;
        }

        while (true)
        {
            comp++; // if (a[j] > pivot)
            if (a[j] > pivot)
                j--;
            else
                break;
        }

        comp++; // if (i <= j)
        if (i <= j)
        {
            Swap(a[i], a[j]);
            i++;
            j--;
        }

        comp++; // while check lại
    }

    comp++; // if (left < j)
    if (left < j)
        quickSort(a, left, j, comp);

    comp++; // if (i < right)
    if (i < right)
        quickSort(a, i, right, comp);
}
// COUNTING SORT
void countingSort(int arr[], int n, long long &comp)
{
    int max = arr[0];

    int i = 1;
    comp++; // check i < n
    while (i < n)
    {
        comp++; // if (arr[i] > max)
        if (arr[i] > max)
        {
            max = arr[i];
        }

        i++;
        comp++; // check lại i < n
    }

    vector<int> count(max + 1, 0);

    i = 0;
    comp++; // check i < n
    while (i < n)
    {
        count[arr[i]]++;
        i++;
        comp++; // check lại
    }

    int index = 0;

    i = 0;
    comp++; // check i <= max
    while (i <= max)
    {
        comp++; // check count[i] > 0
        while (count[i] > 0)
        {
            arr[index] = i;
            index++;
            count[i]--;

            comp++; // check lại count[i] > 0
        }

        i++;
        comp++; // check lại i <= max
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
    int i = 0;

    comp++; // check i < n-1
    while (i < n - 1)
    {
        int j = 0;

        comp++; // check j < n-i-1
        while (j < n - i - 1)
        {
            comp++; // if (a[j] > a[j+1])
            if (a[j] > a[j + 1])
            {
                Swap(a[j], a[j + 1]);
            }

            j++;
            comp++; // check lại j < n-i-1
        }

        i++;
        comp++; // check lại i < n-1
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
    int i = 1;

    comp++; // check i < n
    while (i < n)
    {
        int j = i;

        comp++; // check j > 0
        while (j > 0)
        {
            comp++; // if (arr[j-1] > arr[j])
            if (arr[j - 1] > arr[j])
            {
                Swap(arr[j - 1], arr[j]);
                j--;
            }
            else
                break;

            comp++; // check lại j > 0
        }

        i++;
        comp++; // check lại i < n
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

    int *L = new int[n1];
    int *R = new int[n2];

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

    int *L = new int[n1];
    int *R = new int[n2];

    int i = 0;
    comp++; // check i < n1
    while (i < n1)
    {
        L[i] = a[left + i];
        i++;
        comp++; // check lại
    }

    int j = 0;
    comp++; // check j < n2
    while (j < n2)
    {
        R[j] = a[mid + 1 + j];
        j++;
        comp++; // check lại
    }

    i = 0;
    j = 0;
    int k = left;

    comp++; // check i < n1 && j < n2
    while (i < n1 && j < n2)
    {
        comp++; // if (L[i] <= R[j])
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];

        comp++; // check lại while
    }

    comp++; // check i < n1
    while (i < n1)
    {
        a[k++] = L[i++];
        comp++; // check lại
    }

    comp++; // check j < n2
    while (j < n2)
    {
        a[k++] = R[j++];
        comp++; // check lại
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int a[], int left, int right, long long &comp)
{
    comp++; // if (left < right)
    if (left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(a, left, mid, comp);
        mergeSort(a, mid + 1, right, comp);

        merge(a, left, mid, right, comp);
    }
}
// HEAP SORT
void maxHeapify(int A[], int heap_size, int i)
{
    int l = 2 * i + 1, r = 2 * i + 2, largest = i;

    if (l < heap_size && A[l] > A[i])
        largest = l;
    if (r < heap_size && A[r] > A[largest])
        largest = r;

    if (largest != i)
    {
        Swap(A[i], A[largest]);
        maxHeapify(A, heap_size, largest);
    }
}

void heapSort(int *A, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(A, n, i);

    int heap_size = n;

    for (int i = n - 1; i > 0; i--)
    {
        Swap(A[0], A[i]);
        heap_size--;
        maxHeapify(A, heap_size, 0);
    }
}

void maxHeapify(int A[], int heap_size, int i, long long &comp)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    comp++; // if (l < heap_size)
    if (l < heap_size)
    {
        comp++; // if (A[l] > A[i])
        if (A[l] > A[i])
            largest = l;
    }

    comp++; // if (r < heap_size)
    if (r < heap_size)
    {
        comp++; // if (A[r] > A[largest])
        if (A[r] > A[largest])
            largest = r;
    }

    comp++; // if (largest != i)
    if (largest != i)
    {
        Swap(A[i], A[largest]);
        maxHeapify(A, heap_size, largest, comp);
    }
}

void heapSort(int *A, int n, long long &comp)
{
    int i = n / 2 - 1;

    comp++; // check i >= 0
    while (i >= 0)
    {
        maxHeapify(A, n, i, comp);
        i--;
        comp++; // check lại
    }

    int heap_size = n;

    i = n - 1;
    comp++; // check i > 0
    while (i > 0)
    {
        Swap(A[0], A[i]);
        heap_size--;
        maxHeapify(A, heap_size, 0, comp);

        i--;
        comp++; // check lại
    }
}

// RADIX SORT
int getMaxValue(int arr[], int size)
{
    int maxVal = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }
    return maxVal;
}

int getMaxValue(int arr[], int size, long long &comp)
{
    int maxVal = arr[0];

    int i = 1;
    comp++; // check i < size
    while (i < size)
    {
        comp++; // if (arr[i] > maxVal)
        if (arr[i] > maxVal)
            maxVal = arr[i];

        i++;
        comp++; // check lại i < size
    }

    return maxVal;
}

void countingSortRadix(int arr[], int size, int exponent)
{
    const int base = 10;
    int freCnt[base] = {0};
    int *tmp = new int[size];

    for (int i = 0; i < size; i++)
    {
        int digit = (arr[i] / exponent) % base;
        freCnt[digit]++;
    }

    for (int i = 1; i < base; i++)
        freCnt[i] += freCnt[i - 1];

    for (int i = size - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exponent) % base;
        tmp[--freCnt[digit]] = arr[i];
    }

    for (int i = 0; i < size; i++)
        arr[i] = tmp[i];

    delete[] tmp;
}
void countingSortRadix(int arr[], int size, int exponent, long long &comp)
{
    const int base = 10;
    int freCnt[base] = {0};
    int *tmp = new int[size];

    int i = 0;
    comp++; // check i < size
    while (i < size)
    {
        int digit = (arr[i] / exponent) % base;
        freCnt[digit]++;
        i++;
        comp++; // check lại
    }

    i = 1;
    comp++; // check i < base
    while (i < base)
    {
        freCnt[i] += freCnt[i - 1];
        i++;
        comp++; // check lại
    }

    i = size - 1;
    comp++; // check i >= 0
    while (i >= 0)
    {
        int digit = (arr[i] / exponent) % base;
        tmp[--freCnt[digit]] = arr[i];
        i--;
        comp++; // check lại
    }

    i = 0;
    comp++; // check i < size
    while (i < size)
    {
        arr[i] = tmp[i];
        i++;
        comp++; // check lại
    }

    delete[] tmp;
}
void radixSort(int arr[], int size)
{
    if (size <= 1)
        return;

    int maxValue = getMaxValue(arr, size);

    for (int exponent = 1; maxValue / exponent > 0; exponent *= 10)
        countingSortRadix(arr, size, exponent);
}

void radixSort(int arr[], int size, long long &comp)
{
    comp++; // if (size <= 1)
    if (size <= 1)
        return;

    int maxValue = getMaxValue(arr, size, comp);

    int exponent = 1;

    comp++; // check maxValue / exponent > 0
    while (maxValue / exponent > 0)
    {
        countingSortRadix(arr, size, exponent, comp);

        exponent *= 10;
        comp++; // check lại
    }
}