#ifndef DATAGENERATOR_H
#define DATAGENERATOR_H

template <class T>
void Swap(T &a, T &b);

// Generate different types of input data
void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);

// General function to generate data based on type
void GenerateData(int a[], int n, int dataType);

#endif