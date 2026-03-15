#include<iostream>

using namespace std;

long long BubbleSort(int arr[], int n){
    long long countComparisons = 0;
    bool swapStatus;
    for(int i = 0; i < n - 1; i++){
        swapStatus = false;
        for(int j = 0; j < n - i - 1; j++){
            countComparisons++;
            if(arr[j + 1] < arr[j]){
                swap(arr[j + 1], arr[j]);
            }
        }
        if(!swapStatus){
            break;
        }
    }
    return countComparisons;
}

void BubbleSortNoCounting(int arr[], int n){
    bool swapStatus;
    for(int i = 0; i < n - 1; i++){
        swapStatus = false;
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j + 1] < arr[j]){
                swap(arr[j + 1], arr[j]);
            }
        }
        if(!swapStatus){
            break;
        }
    }
}

long long InsertionSort(int arr[], int n){
    long long countComparisons = 0;
    for(int i = 1; i < n; i++){
        int j = i;
        while(j > 0){
            countComparisons++;
            if(arr[j - 1] > arr[j]){
                swap(arr[j - 1], arr[j]);
                j--;
            } else {
                break;
            }
        }
    }
    return countComparisons;
}

void InsertionSortNoCounting(int arr[], int n){
    for(int i = 1; i < n; i++){
        int j = i;
        while(j > 0){
            if(arr[j - 1] > arr[j]){
                swap(arr[j - 1], arr[j]);
                j--;
            } else {
                break;
            }
        }
    }
}

long long CountingSort(int arr[], int n){
    int countComparisons = 0;
    int max = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    vector<int> count(max + 1, 0);
    for(int i = 0; i < n; i++){
        count[arr[i]]++;
    }
    int index = 0;
    for(int i = 0; i <= max; i++){
        while(count[i] > 0){
            arr[index] = i;
            index++;
            count[i]--;
        }
    }
    return countComparisons;
}

