#include <iostream>
#include <cmath>
using namespace std;

void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

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

void selectionSortCount(int a[], int n, long long &comp)
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

void shellSortCount(int a[], int n, long long &comp)
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

void quickSortCount(int a[], int left, int right, long long &comp)
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
        quickSortCount(a, left, j, comp);

    if(i < right)
        quickSortCount(a, i, right, comp);
}