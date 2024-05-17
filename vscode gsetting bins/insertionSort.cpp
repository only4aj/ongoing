#include <iostream>
#include <fstream>
#include <random>
#include <time.h>
using namespace std;

int Comparision(int size)
{
    int *arr;

    arr = new int[size];

    // Random Numbers Generators
    static mt19937 gen(time(nullptr));
    static uniform_int_distribution<int> distr(10, 100);
    for (int i = 0; i < size; i++)
        arr[i] = distr(gen);

    int j = 0, temp, com = 0;
    for (int i = 0; i < size; i++)
    {
        j = i - 1;
        temp = arr[i];
        while (j >= 0 && temp < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
            com++;
        }
        arr[j + 1] = temp;
    }

    return com;
}

int main()
{

    int size = 30;
    int average = 0;
    int totalSize = 100; // numbers of average of arrays
    ofstream file1("insertionSize.txt");
    ofstream file2("insertionAverage.txt");
    cout << "Program Start......\n";
    for (int i = 0; i < totalSize; i++)
    {
        for (int j = 0; j < 10; j++)
            average += Comparision(size);

        average /= 10;
        i < totalSize - 1 ? file1 << size << "," : file1 << size;
        i < totalSize - 1 ? file2 << average << "," : file2 << average;
        cout << size << "\t\t" << average << endl;
        average = 0;
        size += 9;
    }
    cout << "Program Finish......\n";

    return 0;
}