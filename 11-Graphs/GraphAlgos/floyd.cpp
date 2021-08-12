#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX INT_MAX

void floyd(int n, vector<vector<int>> &dist)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adjm(n, vector<int>(n, 0));

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjm[u][v] = w;
        adjm[v][u] = w;
    }

    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; i++)
        dist[i][i] = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adjm[i][j] != 0)
                dist[i][j] = adjm[i][j];
        }
    }

    floyd(adjm.size(), dist);

    for (auto i : dist)
    {
        for (auto j : i)
        {
            if (j == INT_MAX)
                cout << "INF"
                     << " ";
            else
                cout << j << " ";
        }
        cout << endl;
    }
}