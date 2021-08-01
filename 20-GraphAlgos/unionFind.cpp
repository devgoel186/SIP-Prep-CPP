#include <bits/stdc++.h>
using namespace std;
#define long long ll
#define MAX INT_MAX
#define MOD 1000000007

void makeSet(vector<int> &parent, vector<int> &sizes)
{
    for (int i = 0; i < parent.size(); i++)
    {
        parent[i] = i;
        sizes[i] = 1;
    }
}

int findSet(vector<int> &parent, int v)
{
    if (parent[v] == v)
        return v;
    parent[v] = findSet(parent, parent[v]);
    return parent[v];
}

void unionSet(vector<int> &parent, vector<int> &sizes, int u, int v)
{
    int x = findSet(parent, u);
    int y = findSet(parent, v);
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
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        edges.push_back({x, y});
    }

    vector<int> parent(n, 0);
    vector<int> sizes(n, 0);
    makeSet(parent, sizes);

    bool cycle = false;

    for (int i = 0; i < edges.size(); i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];
        int r1 = findSet(parent, a);
        int r2 = findSet(parent, b);
        if (r1 == r2)
        {
            cycle = true;
            break;
        }
        else
            unionSet(parent, sizes, r1, r2);
    }

    if (cycle)
        cout << "Cycle Present" << endl;
    else
        cout << "No Cycle Present" << endl;
}