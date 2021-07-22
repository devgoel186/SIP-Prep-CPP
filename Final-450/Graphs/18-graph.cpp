/* Kruskal's Algo - Used for calculating MST of a graph */
/* Idea is to include edges with increasing order of weights, 
and skip edges which introduce a cycle in MST */

/* TIME COMPLEXITY = O(E LOG V)
SPACE COMPLEXITY = O(E + V)*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int findSet(vector<int> &parent, const vector<int> &sizes, int v)
{
    if (parent[v] == v)
        return v;
    parent[v] = findSet(parent, sizes, parent[v]);
    return parent[v];
}

void unionSet(vector<int> &parent, vector<int> &sizes, int u, int v)
{
    int x = findSet(parent, sizes, u);
    int y = findSet(parent, sizes, v);
    if (x != y)
    {
        if (sizes[x] < sizes[y])
            swap(x, y);
        parent[y] = x;
        sizes[x] += sizes[y];
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> edges;
    vector<bool> visited(n, false);
    vector<int> parent(n, 0);
    vector<int> sizes(n, 0);

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        sizes[i] = 1;
    }

    int cost = 0;
    sort(edges.begin(), edges.end());

    for (int i = 0; i < e; i++)
    {
        int w = edges[i][0];
        int u = edges[i][1];
        int v = edges[i][2];
        int x = findSet(parent, sizes, u);
        int y = findSet(parent, sizes, v);
        if (x != y)
        {
            cout << u << " " << v << endl;
            cost += w;
            unionSet(parent, sizes, x, y);
        }
    }

    cout << "Total Cost = " << cost << endl;
}