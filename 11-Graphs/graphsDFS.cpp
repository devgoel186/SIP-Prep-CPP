#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(const vector<vector<int>> &adj, vector<bool> &visited, int node)
{
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < adj[node].size(); i++)
    {
        if (!visited[adj[node][i]])
        {
            dfs(adj, visited, adj[node][i]);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adjl(n + 1);
    vector<bool> visited(n + 1, false);

    int x, y;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        adjl[x].push_back(y);
        adjl[y].push_back(x);
    }

    dfs(adjl, visited, 1);
}