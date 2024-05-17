#include <iostream>
#include <fstream>
#include <ctime>
#include <random>
using namespace std;

int count = 0; // It is tore comparisons in array sort in quick sort

// Heapd Sort Processor
void heapify(int arr[], int size, int i)
{
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[largest] < arr[left])
        largest = left;

    if (right < size && arr[largest] < arr[right])
        largest = right;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        count++;
        heapify(arr, size, largest);
    }
}

void heapSort(int arr[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    for (int i = size - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// Create Random values array according to given size
void createArray(int size)
{
    int arr[size];

    // Random Numbers Generators
    static mt19937 gen(time(nullptr));
    static uniform_int_distribution<int> distr(1, 100);
    for (int i = 0; i < size; i++)
        arr[i] = distr(gen);

    heapSort(arr, size);
}

int main()
{
    int size = 30, average = 0, totalSize = 100;
    int comparisonArray[10]; // This is store comparisons of 10 arrays

    ofstream file1("heapSortSizes.txt");    // create a file1 which is store sizes of every arrays
    ofstream file2("heapSortAverages.txt"); // create a this file2 which is store of every 10 arrays average
    cout << "Program Started.........\n";
    for (int i = 0; i < totalSize; i++)
    {
        cout << "Enter in Loop " << (i + 1) << endl;
        for (int j = 0; j < 10; j++)
            createArray(size);

        average = count / 10;
        // write sizes of arrays in file1 from class objects
        i < totalSize - 1 ? file1 << size << "," : file1 << size;
        // write averages of arrays in file1 from class objects
        i < totalSize - 1 ? file2 << average << "," : file2 << average;
        cout << size << "\t" << average << endl;

        average = 0;
        count = 0;
        size += 9;
    }
    cout << "Program Finish\n";
    return 0;
}