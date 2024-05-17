#include <iostream>
#include <fstream>
#include <random>
#include <time.h>
using namespace std;

int count = 0; // It is tore comparisons in array sort in quick sort

// Quick Sort processo
int paritition(int arr[], int high, int low = 0)
{
    int i, j, pivot;
    i = low + 1;
    j = high;
    pivot = low;

    do
    {
        while (arr[i] <= arr[pivot])
            i++;
        while (arr[j] > arr[pivot])
            j--;
        if (i < j)
        {
            swap(arr[i], arr[j]);
            count++;
        }
    } while (i < j);
    swap(arr[j], arr[pivot]);
    return j;
}

void quickSort(int arr[], int high, int low = 0)
{
    int q;
    if (low < high)
    {
        q = paritition(arr, high, low);
        quickSort(arr, q - 1, low);
        quickSort(arr, high, q + 1);
    }
}

// Create Random values array according to given size
void createArray(int size)
{
    int *arr;

    arr = new int[size];

    // Random Numbers Generators
    static mt19937 gen(time(nullptr));
    static uniform_int_distribution<int> distr(10, 100);
    for (int i = 0; i < size; i++)
        arr[i] = distr(gen);

    quickSort(arr, size - 1);
}

int main()
{
    int size = 30, average = 0, totalSize = 100;
    ofstream file1("quickSortSizes.txt");    // create a file1 which is store sizes of every arrays
    ofstream file2("quickSortAverages.txt"); // create a this file2 which is store of every 10 arrays average

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
        cout << size << "\t\t" << average << endl;

        average = 0;
        count = 0;
        size += 9;
    }
    cout << "Program Finished.........\n";

    return 0;
}