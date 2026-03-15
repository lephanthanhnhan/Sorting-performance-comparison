#include <iostream>
#include <cmath>
#include "sort.h"

using namespace std;

void swapInt(int &a, int &b)
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
                swapInt(a[i], a[i + 1]);
                k = i;
            }
        }
        right = k;

        for (int i = right; i > left; i--)
        {
            if (a[i] < a[i - 1])
            {
                swapInt(a[i], a[i - 1]);
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

    while (++comp && left < right)
    {
        for (int i = left; ++comp && i < right; i++)
        {
            if (++comp && a[i] > a[i + 1])
            {
                swapInt(a[i], a[i + 1]);
                k = i;
            }
        }
        right = k;

        for (int i = right; ++comp && i > left; i--)
        {
            if (++comp && a[i] < a[i - 1])
            {
                swapInt(a[i], a[i - 1]);
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
    while (++comp && left <= right)
    {
        int mid = (left + right) / 2;

        if (++comp && item < a[mid])
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

    swapInt(a[maxIndex], a[0]);

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
    if (m <= 2)
        m = 2;

    int minVal = a[0];
    int maxIndex = 0;

    for (int i = 1; ++comp && i < n; i++)
    {
        if (++comp && a[i] < minVal)
            minVal = a[i];
        if (++comp && a[i] > a[maxIndex])
            maxIndex = i;
    }

    if (a[maxIndex] == minVal)
        return;

    int *L = new int[m]();

    double c = (double)(m - 1) / (a[maxIndex] - minVal);

    for (int i = 0; ++comp && i < n; i++)
    {
        int k = int(c * (a[i] - minVal));
        L[k]++;
    }

    for (int i = 1; ++comp && i < m; i++)
        L[i] += L[i - 1];

    swapInt(a[maxIndex], a[0]);

    int move = 0;
    int j = 0;
    int k = m - 1;

    while (++comp && move < n - 1)
    {
        while (++comp && j > L[k] - 1)
        {
            j++;
            k = int(c * (a[j] - minVal));
        }

        int flash = a[j];

        while (++comp && j != L[k])
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

    for (int i = 1; ++comp && i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && (++comp && a[j] > key))
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}