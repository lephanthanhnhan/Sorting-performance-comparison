SORTING ALGORITHMS PROJECT – README

1. Programming Language
   This project is implemented in **C++** and compiled using the **GNU g++ compiler**.

---

2. Libraries Used (GNU Standard Only)

The project uses only standard C++ libraries that are part of the GNU Standard Library.

<iostream> – Console input/output.
<fstream> – Reading and writing files.
<string> – String manipulation.
<ctime> – Measuring running time of algorithms.
<cstdlib> – Utility functions (exit, random functions, stoi).
<cctype> – Character checking (isdigit).

No external or non-standard libraries such as windows.h, conio.h, bits/stdc++.h, etc. are used.

---

3. Project Structure

source/
main.cpp
sort.cpp
sort.h
DataGenerator.cpp
DataGenerator.h

main.cpp
Handles command line arguments, file input/output, algorithm execution, and comparison mode.

sort.cpp / sort.h
Contains implementations of sorting algorithms:
Selection Sort, Insertion Sort, Shell Sort, Bubble Sort, Heap Sort, Merge Sort, Quick Sort, Radix Sort, Counting Sort, Binary Insertion Sort, Shaker Sort, and Flash Sort.

DataGenerator.cpp / DataGenerator.h
Used to generate input data with different data orders:
Randomized, Sorted, Reversed, and Nearly Sorted.

---

4. Compilation

Compile the program using g++:

g++ main.cpp sort.cpp DataGenerator.cpp -o sort.exe

or

g++ \*.cpp -o sort.exe

---

5. Running the Program

The program supports two modes:

Algorithm Mode (-a)
Runs a single sorting algorithm.

Comparison Mode (-c)
Compares two sorting algorithms.

---

COMMAND 1 – Run algorithm on input file

./sort.exe -a selection-sort input.txt -both

./sort.exe -a insertion-sort input.txt -both

./sort.exe -a shell-sort input.txt -both

./sort.exe -a bubble-sort input.txt -both

./sort.exe -a heap-sort input.txt -both

./sort.exe -a merge-sort input.txt -both

./sort.exe -a quick-sort input.txt -both

./sort.exe -a radix-sort input.txt -both

./sort.exe -a counting-sort input.txt -both

./sort.exe -a binary-insertion-sort input.txt -both

./sort.exe -a shaker-sort input.txt -both

./sort.exe -a flash-sort input.txt -both

---

COMMAND 2 – Run algorithm with generated data

./sort.exe -a quick-sort 10000 -rand -both

./sort.exe -a merge-sort 10000 -sorted -both

./sort.exe -a heap-sort 10000 -rev -both

./sort.exe -a shell-sort 10000 -nsorted -both

---

COMMAND 3 – Run algorithm on all input orders

./sort.exe -a quick-sort 10000 -both

./sort.exe -a merge-sort 10000 -both

---

COMMAND 4 – Compare two algorithms using input file

./sort.exe -c quick-sort merge-sort input.txt

./sort.exe -c heap-sort quick-sort input.txt

./sort.exe -c bubble-sort insertion-sort input.txt

---

COMMAND 5 – Compare two algorithms with generated data

./sort.exe -c quick-sort merge-sort 10000 -rand

./sort.exe -c heap-sort shell-sort 10000 -sorted

./sort.exe -c bubble-sort insertion-sort 10000 -rev

---

6. Notes

All libraries used belong to the GNU Standard Library.
No external dependencies are required to compile or run the program.
