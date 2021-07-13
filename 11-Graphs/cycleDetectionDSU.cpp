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

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adjl(n);
    vector<int> parent(n);
    vector<int> sizes(n);

    for (int i = 0; i < n; i++)
    {
        makeSet(parent, sizes, i);
    }

    int x, y;
    vector<vector<int>> edges;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        // adjl[x].push_back(y);
        // adjl[y].push_back(x);
        edges.push_back({x, y});
    }

    bool cycle = false;

    for (int i = 0; i < edges.size(); i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];
        int r1 = findSet(parent, sizes, a);
        int r2 = findSet(parent, sizes, b);
        if (r1 == r2)
            cycle = true;
        else
            unionSet(parent, sizes, r1, r2);
    }

    cycle ? cout << "Cycle Detected" << endl : cout << "No cycle present" << endl;
}