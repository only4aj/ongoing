#include <iostream>
#include <queue>
using namespace std;

// This is Advance BFS Algorithm Technique
void bfs(int size)
{
    int arr[size], visited[size];
    int startNode, nodeIndex, index, n, a;
    int rf[size][size];
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

    visited[nodeIndex] = 1;
    q.push(arr[nodeIndex]);
    cout << arr[nodeIndex] << " ";
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int i = 0; i < size; i++)
            if (node == arr[i])
                index = i;

        for (int j = 0; j < size; j++)
            if (rf[index][j] == 1 && visited[j] == 0)
            {
                cout << arr[j] << " ";
                visited[j] = 1;
                q.push(arr[j]);
            }
    }
}

// This is simple BFS Technique
void bfs()
{
    int size;
    int k = 3, n, a;
    queue<int> q;
    cout << "Enter number of node in graph : ";
    cin >> size;
    int visited[size];
    int rf[size][size];

    for (int i = 0; i < size; i++)
        visited[i] = 0;

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            rf[i][j] = 0;

    for (int i = 0; i < size; i++)
    {
        cout << "Enter number of connected nodes of node " << i << " : ";
        cin >> n;
        cout << "Enter all connect nodes :\n";
        for (int j = 0; j < n; j++)
        {
            cin >> a;
            rf[i][a] = 1;
            rf[a][i] = 1;
        }
    }

    visited[k] = 1;
    q.push(k);
    cout << k << " ";

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int j = 0; j < size; j++)
        {
            if (rf[node][j] == 1 && visited[j] == 0)
            {
                cout << j << " ";
                visited[j] = 1;
                q.push(j);
            }
        }
    }
}

int main()
{
    int size;
    cout << "Enter number of nodes in graph : ";
    cin >> size;
    bfs(size);
    // bfs();

    return 0;
}