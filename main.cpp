#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cctype>
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

void runAlgorithm(string algorithm, int a[], int n, long long &comp)
{
    if (algorithm == "shaker-sort")
        shakerSort(a, n, comp);

    else if (algorithm == "binary-insertion-sort")
        binaryInsertionSort(a, n, comp);

    else if (algorithm == "flash-sort")
        flashSort(a, n, comp);

    else if (algorithm == "selection-sort")
        selectionSort(a, n, comp);

    else if (algorithm == "shell-sort")
        shellSort(a, n, comp);

    else if (algorithm == "quick-sort")
        quickSort(a, 0, n - 1, comp);

    else if (algorithm == "bubble-sort")
        bubbleSort(a, n, comp);

    else if (algorithm == "insertion-sort")
        insertionSort(a, n, comp);

    else if (algorithm == "counting-sort")
        countingSort(a, n, comp);

    else if (algorithm == "merge-sort")
        mergeSort(a, 0, n - 1, comp);

    else if (algorithm == "heap-sort")
        heapSort(a, n, comp);

    else if (algorithm == "radix-sort")
        radixSort(a, n, comp);
}

bool isNumber(string s)
{
    for (char c : s)
        if (!isdigit(c))
            return false;
    return true;
}
int main(int argc, char *argv[])
{
    const int MAXN = 1000000;

    int *a = new int[MAXN];
    int *b = new int[MAXN];
    int n;

    long long comp = 0, comp2 = 0;
    double time = 0, time2 = 0;

    clock_t start, end;
    if (argc < 2)
    {
        cout << "Invalid command\n";
        return 0;
    }
    string mode = argv[1];

    // ================= ALGORITHM MODE =================
    if (mode == "-a")
    {
        string algorithm = argv[2];
        string param = argv[3];
        cout << "ALGORTHM MODE" << endl;
        cout << "Algorithm: " << argv[2] << endl;

        // Command 1 hoặc Command 3
        if (argc == 5)
        {
            string option = argv[4];

            // COMMAND 3: input size
            if (isNumber(param))
            {
                n = stoi(param);
                cout << "Input size: " << n << endl;
                cout << endl;
                for (int i = 0; i < 4; i++)
                {
                    comp = 0;

                    GenerateData(a, n, i);

                    start = clock();
                    runAlgorithm(algorithm, a, n, comp);
                    end = clock();

                    time = (double)(end - start) / CLOCKS_PER_SEC * 1000;
                    string inputOrder;
                    if (i == 0)
                        inputOrder = "Randomize";
                    if (i == 1)
                        inputOrder = "Nearly Sorted";
                    if (i == 2)
                        inputOrder = "Sorted";
                    if (i == 3)
                        inputOrder = "Reversed";
                    cout << "Input order: " << inputOrder << endl;
                    cout << "-------------------------------" << endl;
                    if (option == "-time")
                        cout << "Running time: " << time << " ms\n";
                    else if (option == "-comp")
                        cout << "Comparisons: " << comp << endl;
                    else
                    {
                        cout << "Running time: " << time << " ms\n";
                        cout << "Comparisons: " << comp << endl;
                    }
                    cout << endl;
                    string filename = "input_" + to_string(i + 1) + ".txt";
                    writeFile(filename, a, n);
                }
            }

            // COMMAND 1: input file
            else
            {
                cout << "Input file: " << param << endl;
                readFile(param, a, n);
                cout << "Input size: " << n << endl;
                cout << "--------------------------------------" << endl;
                start = clock();
                runAlgorithm(algorithm, a, n, comp);
                end = clock();

                time = (double)(end - start) / CLOCKS_PER_SEC * 1000;

                if (option == "-time")
                    cout << "Running time: " << time << " ms\n";
                else if (option == "-comp")
                    cout << "Comparisons: " << comp << endl;
                else
                {
                    cout << "Running time: " << time << " ms\n";
                    cout << "Comparisons: " << comp << endl;
                }

                writeFile("output.txt", a, n);
            }
        }

        // COMMAND 2
        else if (argc == 6)
        {
            n = stoi(argv[3]);
            string order = argv[4];
            string option = argv[5];
            cout << "Input size: " << n << endl;

            int dataType;

            if (order == "-rand")
            {
                dataType = 0;
                cout << "Input order: GenerateRandomData" << endl;
            }
            else if (order == "-sorted")
            {
                dataType = 1;
                cout << "Input order: GenerateSortedData" << endl;
            }
            else if (order == "-rev")
            {
                dataType = 2;
                cout << "Input order: GenerateReverseData" << endl;
            }
            else if (order == "-nsorted")
            {
                dataType = 3;
                cout << "Input order: GenerateNearlySortedData" << endl;
            }
            cout << "-------------------------" << endl;
            GenerateData(a, n, dataType);

            writeFile("input.txt", a, n);

            start = clock();
            runAlgorithm(algorithm, a, n, comp);
            end = clock();

            time = (double)(end - start) / CLOCKS_PER_SEC * 1000;

            if (option == "-time")
                cout << "Running time: " << time << " ms\n";
            else if (option == "-comp")
                cout << "Comparisons: " << comp << endl;
            else
            {
                cout << "Running time: " << time << " ms\n";
                cout << "Comparisons: " << comp << endl;
            }

            writeFile("output.txt", a, n);
        }
    }
    // ================= COMPARISON MODE =================
    else if (mode == "-c")
    {
        string alg1 = argv[2];
        string alg2 = argv[3];
        cout << "COMPARE MODE" << endl;
        cout << "Algorithm: " << argv[2] << "|" << argv[3] << endl;
        // Command 4
        if (argc == 5)
        {
            string inputfile = argv[4];

            readFile(inputfile, a, n);
            cout << "Input file: " << inputfile << endl;
            cout << "Input size: " << n << endl;
            cout << "------------------------------" << endl;
            for (int i = 0; i < n; i++)
                b[i] = a[i];

            start = clock();
            runAlgorithm(alg1, a, n, comp);
            end = clock();
            time = (double)(end - start) / CLOCKS_PER_SEC * 1000;

            start = clock();
            runAlgorithm(alg2, b, n, comp2);
            end = clock();
            time2 = (double)(end - start) / CLOCKS_PER_SEC * 1000;

            cout << "Running time: " << alg1 << ": " << time << " ms | " << alg2 << ": " << time2 << " ms\n";
            cout << "Comparisons: " << alg1 << ": " << comp << "| " << alg2 << ": " << comp2 << "\n";
        }

        // Command 5
        else if (argc == 6)
        {
            n = stoi(argv[4]);
            string order = argv[5];
            cout << "Input size: " << n << endl;
            int dataType;

            if (order == "-rand")
            {
                dataType = 0;
                cout << "Input order: GenerateRandomData" << endl;
            }
            else if (order == "-sorted")
            {
                dataType = 1;
                cout << "Input order: GenerateSortedData" << endl;
            }
            else if (order == "-rev")
            {
                dataType = 2;
                cout << "Input order: GenerateReverseData" << endl;
            }
            else if (order == "-nsorted")
            {
                dataType = 3;
                cout << "Input order: GenerateNearlySortedData" << endl;
            }
            cout << "-------------------------" << endl;

            GenerateData(a, n, dataType);

            for (int i = 0; i < n; i++)
                b[i] = a[i];

            start = clock();
            runAlgorithm(alg1, a, n, comp);
            end = clock();
            time = (double)(end - start) / CLOCKS_PER_SEC * 1000;

            start = clock();
            runAlgorithm(alg2, b, n, comp2);
            end = clock();
            time2 = (double)(end - start) / CLOCKS_PER_SEC * 1000;

            cout << "Running time: " << alg1 << ": " << time << " ms | " << alg2 << ": " << time2 << " ms\n";
            cout << "Comparisons: " << alg1 << ": " << comp << "| " << alg2 << ": " << comp2 << "\n";

            writeFile("input.txt", a, n);
        }
    }

    delete[] a;
    delete[] b;

    return 0;
}