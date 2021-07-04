#include <iostream>
#include <limits.h>
using namespace std;

int findMinVertex(int *weights, bool *visited, int n)
{
    int minVertex = -1;
}

void primsAlgo(int **edges, int n)
{
    int *parent = new int[n];
    int *weights = new int[n];
    bool *visited = new bool[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        weights[i] = INT_MAX;
    }

    parent[0] = -1;
    weights[0] = 0;

    for (int i = 0; i < n; i++)
    {
        int minVertex = findMinVertex(weights, visited, n);
        for (int j = 0; j < n; j++)
        {
            if (edges[minVertex][j] != 0 && !visited[j])
            {
                weights[j] = edges[minVertex][j];
                parent[j] = minVertex;
            }
        }
    }
}

int main()
{
    int n, e;
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
        int s, d, weight;
        cin >> s >> d >> weight;
        edges[s][d] = 1;
        edges[d][s] = 1;
    }
}