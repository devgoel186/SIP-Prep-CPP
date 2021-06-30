#include <iostream>
#include <queue>
using namespace std;

void printDFS(int **edges, int n, int sv, bool *visited)
{
    cout << sv << " ";
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
            continue;
        if (edges[sv][i] == 1)
        {
            if (visited[i])
                continue;
            printDFS(edges, n, i, visited);
        }
    }
}

void printBFS(int **edges, int n, int sv)
{
    queue<int> pendingNodes;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    pendingNodes.push(sv);
    visited[sv] = true;

    while (!pendingNodes.empty())
    {
        int curr = pendingNodes.front();
        pendingNodes.pop();
        cout << curr << " ";
        for (int i = 0; i < n; i++)
        {
            if (curr == i)
                continue;
            if (edges[curr][i] == 1 && !visited[i])
            {
                pendingNodes.push(i);
                visited[i] = true;
            }
        }
    }
    delete[] visited;
}

void deleteMemory(int **edges, int n, bool *visited)
{
    delete[] visited;
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
}

int main()
{
    int n;
    int e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    cout << "DFS" << endl;
    printDFS(edges, n, 0, visited);
    cout << endl;

    cout << "BFS" << endl;
    printBFS(edges, n, 0);
    cout << endl;

    deleteMemory(edges, n, visited);
}