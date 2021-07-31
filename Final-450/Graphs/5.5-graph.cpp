#include <bits/stdc++.h>
using namespace std;
#define ll long long

int findSet(vector<int> &parent, int a)
{
    if (parent[a] == a)
        return a;
    parent[a] = findSet(parent, parent[a]);
    return parent[a];
}

int unionSet(vector<int> parent, int a, int b)
{
    int x = findSet(parent, a);
    int y = findSet(parent, b);
    if (x != y)
    {
        parent[x] = y;
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adjl(n);
    vector<bool> visited(n, false);
    vector<int> parent(n, 0);

    int x, y;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        adjl[x].push_back(y);
        adjl[y].push_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
}