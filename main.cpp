#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "sort.h"
#include "DataGenerator.h"

using namespace std;

void readFile(string filename, int a[], int &n)
{
    ifstream fin(filename);

    if (!fin)
    {
        cout << "Cannot open input file\n";
        exit(1);
    }

    fin >> n;

    for (int i = 0; i < n; i++)
        fin >> a[i];

    fin.close();
}

void writeFile(string filename, int a[], int n)
{
    ofstream fout(filename);

    fout << n << endl;

    for (int i = 0; i < n; i++)
        fout << a[i] << " ";

    fout.close();
}

int main(int argc, char *argv[])
{
    int *a = new int[1000000];
    int n;

    long long comp = 0;
    double time = 0;

    clock_t start, end;

    string mode = argv[1];
    string algorithm = argv[2];

    // CASE 1: input là file
    if (argc == 5)
    {
        string inputfile = argv[3];
        string option = argv[4];

        readFile(inputfile, a, n);

        start = clock();

        if (algorithm == "shaker-sort")
            shakerSort(a, n, comp);
        else if (algorithm == "binary-insertion-sort")
            binaryInsertionSort(a, n, comp);
        else if (algorithm == "flash-sort")
            flashSort(a, n, comp);

        end = clock();

        time = (double)(end - start) / CLOCKS_PER_SEC * 1000;

        if (option == "-time")
            cout << "Running time: " << time << " ms\n";
        else if (option == "-comp")
            cout << "Comparisons: " << comp << endl;
        else if (option == "-both")
        {
            cout << "Running time: " << time << " ms\n";
            cout << "Comparisons: " << comp << endl;
        }
    }

    // CASE 2: generate data
    else if (argc == 6)
    {
        n = stoi(argv[3]);
        string order = argv[4];
        string option = argv[5];

        int dataType;

        if (order == "-rand")
            dataType = 0;
        else if (order == "-sorted")
            dataType = 1;
        else if (order == "-rev")
            dataType = 2;
        else if (order == "-nsorted")
            dataType = 3;

        GenerateData(a, n, dataType);

        writeFile("input.txt", a, n);

        start = clock();

        if (algorithm == "shaker-sort")
            shakerSort(a, n, comp);
        else if (algorithm == "binary-insertion-sort")
            binaryInsertionSort(a, n, comp);
        else if (algorithm == "flash-sort")
            flashSort(a, n, comp);

        end = clock();

        time = (double)(end - start) / CLOCKS_PER_SEC * 1000;

        if (option == "-time")
            cout << "Running time: " << time << " ms\n";
        else if (option == "-comp")
            cout << "Comparisons: " << comp << endl;
        else if (option == "-both")
        {
            cout << "Running time: " << time << " ms\n";
            cout << "Comparisons: " << comp << endl;
        }
    }

    writeFile("output.txt", a, n);

    delete[] a;
    return 0;
}