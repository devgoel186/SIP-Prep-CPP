#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX INT_MAX

void dfs(vector<vector<int>> &adjl, vector<int> &visited, int src)
{
    visited[src] = true;
    cout << src << " ";

    for (auto i : adjl[src])
    {
        if (!visited[i])
            dfs(adjl, visited, i);
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adjl(n);
    vector<int> visited(n, false);

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adjl[u].push_back(v);
        adjl[v].push_back(u);
    }

    dfs(adjl, visited, 0);
}