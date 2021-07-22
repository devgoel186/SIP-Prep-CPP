#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> edges;
    vector<int> distance(n, INT_MAX);

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int source;
    cin >> source;
    distance[source] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            if (distance[u] != INT_MAX)
                distance[v] = min(distance[v], distance[u] + w);
        }

        for (auto it : distance)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}