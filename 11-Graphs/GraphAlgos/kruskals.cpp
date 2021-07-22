#include <bits/stdc++.h>
using namespace std;
#define ll long long

int findSet(vector<int> &parent, int v)
{
    if (parent[v] == v)
        return v;
    parent[v] = findSet(parent, parent[v]);
    return parent[v];
}

void unionSet(vector<int> &parent, vector<int> &sizes, int a, int b)
{
    int x = findSet(parent, a);
    int y = findSet(parent, b);
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
    vector<int> parent(n, 0);
    vector<int> sizes(n, 0);
    vector<bool> visited(n, false);

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }

    sort(edges.begin(), edges.end());

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        sizes[i] = 1;
    }

    for (int i = 0; i < e; i++)
    {
        int x = findSet(parent, edges[i][1]);
        int y = findSet(parent, edges[i][2]);
        if (x != y)
        {
            cout << edges[i][1] << " " << edges[i][2] << endl;
            unionSet(parent, sizes, edges[i][1], edges[i][2]);
        }
    }
}