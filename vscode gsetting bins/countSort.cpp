#include <iostream>
using namespace std;

// Count Sort Processor
void countSort(int arr[], int size)
{
    int max = arr[0];
    int *countArr;

    // Max Element Search
    for (int i = 1; i < size; i++)
        if (max < arr[i])
            max = arr[i];

    // New Array create thier size is max element
    countArr = new int[max];
    for (int i = 0; i <= max; i++)
        countArr[i] = 0;

    for (int i = 0; i < size; i++)
        countArr[arr[i]] += 1;

    int j = 0, k = 0;
    int arr2[max];

    while (j <= max)
        if (countArr[j] != 0)
        {
            arr[k++] = j;
            countArr[j] -= 1;
        }
        else
            j++;
}

int main()
{
    int *arr, size;

    cout << "Enter size of array : ";
    cin >> size;

    arr = new int[size];

    cout << "Enter all values \n";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    cout << "Before Count Sort\n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    countSort(arr, size);

    cout << "After Count Sort\n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}