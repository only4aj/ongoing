#include <iostream>
using namespace std;

int minKey(int key[], int visited[], int size)
{
    int min = INT32_MAX, minIndex;

    for (int i = 0; i < size; i++)
        if (key[i] < min && !visited[i])
            minIndex = i, min = key[i];
    return minIndex;
}

void mst(int size = 6)
{
    // ------->> Trail Code Adancy MAtrix
    // int adjancyMatrix[size][size] = {{0, 1, 9, 0, 0, 14},
    //                            {1, 0, 10, 15, 0, 0},
    //                            {9, 10, 0, 11, 0, 2},
    //                            {0, 15, 11, 0, 6, 0},
    //                            {0, 0, 0, 6, 0, 9},
    //                            {14, 0, 2, 0, 9, 0}};
    int arr[size];
    int adjancyMatrix[size][size];
    int index, node, n, a, cost;

    int key[size], visited[size], parent[size];

    // key's assign with infinite values
    // visited default false
    for (int i = 0; i < size; i++)
        visited[i] = 0, key[i] = INT32_MAX;

    // Adjancy Matrix allote with 0
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            adjancyMatrix[i][j] = 0;

    // Values of Node taking
    cout << "Enter all node values : \n";
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    // Taking Connected with cost of every node
    for (int i = 0; i < size; i++)
    {
        cout << "Enter number of connected nodes of node " << arr[i] << " : ";
        cin >> n;
        cout << "Enter all connect nodes :\n";
        for (int j = 0; j < n; j++)
        {
            cout << "Node : ";
            cin >> a;
            for (int k = 0; k < size; k++)
                if (a == arr[k])
                {
                    if (!adjancyMatrix[i][k] && !adjancyMatrix[k][i])
                    {
                        cout << "Cost : ";
                        cin >> cost;
                        adjancyMatrix[i][k] = cost;
                        adjancyMatrix[k][i] = cost;
                        break;
                    }
                }
        }
    }

    key[0] = 0; // Cost between Two Vertices

    parent[0] = -1; // Store Parent Node of Each Node

    for (int i = 0; i < size - 1; i++)
    {
        int min = minKey(key, visited, size); // minimum value find in row from adjancy matrix

        visited[min] = 1; // visited node true

        // set parent node and their cost
        for (int j = 0; j < size; j++)
            if (adjancyMatrix[min][j] && visited[j] == 0 && adjancyMatrix[min][j] < key[j])
                key[j] = adjancyMatrix[min][j], parent[j] = min;
    }

    cout << "Edge \tWeight \n";
    for (int i = 1; i < size; i++)
        cout << parent[i] << " - " << i << "\t-> " << adjancyMatrix[i][parent[i]] << endl;
}

int main()
{
    int size;
    cout << "Enter no of nodes of graph : ";
    cin >> size;
    mst(size);
    return 0;
}
