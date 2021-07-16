#include <bits/stdc++.h>
using namespace std;

int primsMST(vector<vector<vector<int>>> &adj, vector<bool> &visited, vector<int> &parent, int source)
{
    vector<int> dist(adj.size(), INT_MAX);

    set<vector<int>> s;
    s.insert({0, source});
    /* {weight, vertex} */

    dist[source] = 0;
    int cost = 0;

    while (!s.empty())
    {
        /* Start from source vertex, which is any random vertex */
        auto x = *(s.begin());
        s.erase(x);
        visited[x[1]] = true;

        int u = x[1];
        int v = parent[x[1]];
        int w = x[0];

        cout << u << " " << v << " " << w << "\n";
        cost += w;

        /* Iterate on all edges from the source vertex */
        for (auto i : adj[x[1]])
        {
            if (visited[i[0]]) /* if visited then continue */
                continue;
            if (dist[i[0]] > i[1]) /* else, if the distance array value is greater than actual weight, update dist array */
            {
                s.erase({dist[i[0]], i[0]});
                dist[i[0]] = i[1];
                s.insert({dist[i[0]], i[0]});
                parent[i[0]] = x[1];
            }
        }
    }
    return cost;
}

int main()
{
    int n, e;
    cin >> n >> e;

    vector<vector<vector<int>>> adj;
    vector<bool> visited(n, false);
    vector<int> parent(n);

    int u, v, w;
    for (int i = 0; i < n; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int costPrims = primsMST(adj, visited, parent, 0);
    cout << "Cost = " << costPrims << endl;
}

/* If implemented using adjacency list, prims algo reaches O(E LOG V) complexity, 
otherwise it goes up to O(V^2) */