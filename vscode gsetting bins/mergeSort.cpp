#include <iostream>
#include <fstream>
#include <random>
#include <time.h>
using namespace std;

int count = 0; // It is tore comparisons in array sort in quick sort

// Merge Sort processo
int merge(int arr[], int low, int mid, int high)
{
    int i, j, k, *arrb;
    arrb = new int[high + 1];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        arr[i] < arr[j] ? arrb[k++] = arr[i++] : arrb[k++] = arr[j++];
        count++;
    }

    while (i <= mid)
        arrb[k++] = arr[i++];

    while (j <= high)
        arrb[k++] = arr[j++];

    for (int l = low; l <= high; l++)
        arr[l] = arrb[l];
    delete[] arrb;
    return count;
}

int mergeSort(int arr[], int high, int low = 0)
{
    int mid, comp = 0;
    if (low < high)
    {
        mid = (high + low) / 2;
        mergeSort(arr, mid, low);
        mergeSort(arr, high, mid + 1);
        comp = merge(arr, low, mid, high);
    }
    return comp;
}

// Create Random values array according to given size
int createArray(int size)
{
    int *arr;

    arr = new int[size];
    // Random Numbers Generators
    static mt19937 gen(time(nullptr));
    static uniform_int_distribution<int> distr(10, 100);
    for (int i = 0; i < size; i++)
        arr[i] = distr(gen);

    return mergeSort(arr, size - 1);
}

int main()
{
    int size = 30, average = 0, totalSize = 100;

    ofstream file1("mergeSizes.txt");    // create a file1 which is store sizes of every arrays
    ofstream file2("mergeAverages.txt"); // create a this file2 which is store of every 10 arrays average
    cout << "Program Start.......\n";
    for (int i = 0; i < totalSize; i++)
    {
        cout << "Enter in Loop " << (i + 1) << endl;
        for (int j = 0; j < 10; j++)
            average += createArray(size);

        average /= 10;
        // write sizes of arrays in file1 from class objects
        i < totalSize - 1 ? file1 << size << "," : file1 << size;
        // write averages of arrays in file1 from class objects
        i < totalSize - 1 ? file2 << average << "," : file2 << average;
        cout << size << "\t\t" << average << endl;
        count = 0;
        average = 0;
        size += 9;
    }
    cout << "Program Finish.......\n";

    return 0;
}