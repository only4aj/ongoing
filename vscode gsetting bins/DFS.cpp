#include <iostream>
#include <queue>
using namespace std;

int size;
int **rf;

void dfs(int arr[], int visited[], int size, int i)
{
    int index;
    cout << i << " ";
    for (int j = 0; j < size; j++)
        if (i == arr[j])
        {
            index = j;
            break;
        }
    visited[index] = 1;

    for (int j = 0; j < size; j++)
        if (rf[index][j] && !visited[j])
            dfs(arr, visited, size, arr[j]);
}

void createArr()
{
    int arr[size], visited[size];
    int startNode, nodeIndex, index, n, a;
    rf = new int *[size];
    for (int i = 0; i < size; i++)
        rf[i] = new int[size];

    queue<int> q;

    for (int i = 0; i < size; i++)
        visited[i] = 0;

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            rf[i][j] = 0;

    cout << "Enter all values of graph :\n";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    cout << "Enter started node : ";
    cin >> startNode;

    bool check = true;
    for (int i = 0; i < size; i++)
        if (startNode == arr[i])
        {
            nodeIndex = i;
            check = false;
        }
    if (check)
    {
        cout << "Start node not part of graph";
        return;
    }

    for (int i = 0; i < size; i++)
    {
        cout << "Enter number of connected nodes of node " << arr[i] << " : ";
        cin >> n;
        if (!n)
            continue;
        cout << "Enter all connect nodes :\n";
        for (int j = 0; j < n; j++)
        {
            cin >> a;
            for (int k = 0; k < size; k++)
                if (a == arr[k])
                {
                    rf[i][k] = 1;
                    rf[k][i] = 1;
                    break;
                }
        }
    }
    dfs(arr, visited, size, arr[nodeIndex]);
}

int main()
{
    cout << "Enter number of nodes in graph : ";
    cin >> size;
    createArr();
    return 0;
}