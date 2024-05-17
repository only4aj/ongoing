#include <iostream>
using namespace std;

int main()
{
    int row1, col1, row2, col2, row, col;

    // Matrix 1:
    cout << "Enter no of rows in 1st Matrix : ";
    cin >> row1;
    cout << "Enter no of columns in 1st Matrix : ";
    cin >> col1;

    int matrix1[row1][col1];

    cout << "Enter all elements of Matrix \n";
    for (int i = 0; i < row1; i++)
        for (int j = 0; j < col1; j++)
            cin >> matrix1[i][j];

    // Matrix 1:
    cout << "Enter no of rows in 2nd Matrix : ";
    cin >> row2;
    cout << "Enter no of columns in 2nd Matrix : ";
    cin >> col2;

    if (col1 != row2)
    {
        cout << "Multiplication Condition Fail!";
        return 0;
    }
    int matrix2[row2][col2];

    cout << "Enter all elements of Matrix \n";
    for (int i = 0; i < row2; i++)
        for (int j = 0; j < col2; j++)
            cin >> matrix2[i][j];

    int matrix[row1][col2];
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            matrix[i][j] = 0;
            for (int k = 0; k < col1; k++)
                matrix[i][j] += matrix1[i][k] * matrix2[k][j];
        }
    }
    cout << "After Multiplication : \n";
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}