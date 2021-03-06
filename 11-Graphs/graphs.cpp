#include <iostream>
#include <queue>
#include <vector>
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

void printBFS(int **edges, int n, int sv, bool *visited)
{
    queue<int> pendingNodes;

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

void DFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            printDFS(edges, n, i, visited);
    }
    delete[] visited;
}

void BFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            printBFS(edges, n, i, visited);
    }
    delete[] visited;
}

bool hasPathHelper(int **edges, int n, int sv, int ev, bool *visited)
{
    visited[sv] = true;
    bool res = false;

    if (sv == ev)
        return true;

    for (int i = 0; i < n; i++)
    {
        if (i == sv)
            continue;
        if (edges[sv][i] == 1)
        {
            if (visited[i])
                continue;
            res = hasPathHelper(edges, n, i, ev, visited);
            if (res)
                return res;
        }
    }
    return res;
}

bool hasPath(int **edges, int n, int sv, int ev)
{
    bool *visited = new bool[n];
    bool res = false;
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    res = hasPathHelper(edges, n, sv, ev, visited);
    delete[] visited;
    return res;
}

vector<int> *getPathDFSHelper(int **edges, int n, int sv, int ev, bool *visited)
{
    visited[sv] = true;
    vector<int> *res = new vector<int>;
    if (sv == ev)
    {
        res->push_back(sv);
        return res;
    }

    res = NULL;

    for (int i = 0; i < n; i++)
    {
        if (i == sv)
            continue;
        if (edges[sv][i] == 1)
        {
            if (visited[i])
                continue;
            vector<int> *temp = getPathDFSHelper(edges, n, i, ev, visited);
            if (temp != NULL)
            {
                temp->push_back(sv);
                return temp;
            }
        }
    }

    return res;
}

vector<int> *getPathDFS(int **edges, int n, int sv, int ev)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    vector<int> *res = getPathDFSHelper(edges, n, sv, ev, visited);
    delete[] visited;
    return res;
}

// bool isConnectedHelper(int **edges, int n, int sv, bool *visited)
// {
//     visited[sv] = true;
//     bool res = false;

//     if (sv == ev)
//         return true;

//     for (int i = 0; i < n; i++)
//     {
//         if (i == sv)
//             continue;
//         if (edges[sv][i] == 1)
//         {
//             if (visited[i])
//                 continue;
//             res = hasPathHelper(edges, n, i, ev, visited);
//             if (res)
//                 return res;
//         }
//     }
//     return res;
// }

// bool isConnected(int **edges, int n)
// {
//     bool *visited = new bool[n];
//     for (int i = 0; i < n; i++)
//     {
//         visited[i] = false;
//     }
//     bool res = isConnectedHelper(edges, n, 0, visited);
//     delete[] visited;
//     return res;
// }

void deleteMemory(int **edges, int n)
{
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

    cout << "DFS" << endl;
    DFS(edges, n);
    cout << endl;

    cout << "BFS" << endl;
    BFS(edges, n);
    cout << endl;

    cout << "Has Path ? = " << hasPath(edges, n, 0, 2) << endl;

    cout << "Get Path ? = " << endl;
    vector<int> *output = getPathDFS(edges, n, 0, 2);
    for (auto it = output->rbegin(); it != output->rend(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    deleteMemory(edges, n);
}