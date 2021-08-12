#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX INT_MAX

bool bellman(vector<vector<int>> &edges, vector<int> &dist, int n, int src)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < edges.size(); j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            dist[v] = min(dist[v], dist[u] + w);
        }
    }

    for (int j = 0; j < edges.size(); j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if (dist[v] > dist[u] + w)
            return false;
    }

    return true;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> edges;

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int src;
    cin >> src;

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    bool possible = bellman(edges, dist, n, src);

    if (!possible)
    {
        cout << "Graph contains negative cycle!" << endl;
        exit(0);
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << dist[i] << endl;
    }
}