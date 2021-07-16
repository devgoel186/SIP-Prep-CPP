/* MST is the tree where the cost is minimum among all the spanning trees */

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void makeSet(vector<int> &parent, vector<int> &sizes, int v)
{
    parent[v] = v;
    sizes[v] = 1;
}

int findSet(vector<int> &parent, const vector<int> &sizes, int v)
{
    if (v == parent[v])
        return v;
    parent[v] = findSet(parent, sizes, parent[v]);
    return parent[v];
}

void unionSet(vector<int> &parent, vector<int> &sizes, int a, int b)
{
    a = findSet(parent, sizes, a);
    b = findSet(parent, sizes, b);

    if (a != b)
    {
        if (sizes[a] < sizes[b])
            swap(a, b);
        parent[b] = a;
        sizes[a] += sizes[b];
    }
}

bool compare(vector<int> v1, vector<int> v2)
{
    return v1[2] < v2[2];
}

/* 
TIME COMPLEXITY = O(E LOG V)
SPACE COMPLEXITY = O(E + V)
*/
int kruskals(const vector<vector<int>> &edges, vector<int> &parent, vector<int> &sizes)
{
    int cost = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        int x = findSet(parent, sizes, u);
        int y = findSet(parent, sizes, v);
        if (x == y)
            continue;
        else
        {
            cout << u << " " << v << " -- ";
            cost += w;
            unionSet(parent, sizes, u, v);
        }
    }

    return cost;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adjl(n);
    vector<bool> visited(n, false);
    vector<int> parent(n);
    vector<int> sizes(n);

    for (int i = 0; i < n + 1; i++)
    {
        makeSet(parent, sizes, i);
    }

    vector<vector<int>> edges;
    int u, v, w;
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    sort(edges.begin(), edges.end(), compare);

    int res = kruskals(edges, parent, sizes);
    cout << "\nCost = " << res << endl;
}