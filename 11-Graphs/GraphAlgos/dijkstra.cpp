#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX INT_MAX

vector<int> dijkstra(vector<vector<pair<int, int>>> &graph, int src)
{
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty())
    {
        pair<int, int> top = pq.top();
        int u = top.second;
        pq.pop();

        for (auto i : graph[u])
        {
            int v = i.first;
            int w = i.second;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<pair<int, int>>> adjl(n);

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjl[u].push_back({v, w});
        adjl[v].push_back({u, w});
    }

    int src;
    cin >> src;

    vector<int> sssp = dijkstra(adjl, src);

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << sssp[i] << endl;
    }
}