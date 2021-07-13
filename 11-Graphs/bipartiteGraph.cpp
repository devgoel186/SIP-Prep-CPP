#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(const vector<vector<int>> &adj, vector<bool> &visited, int node, vector<int> &color)
{
    visited[node] = true;
    for (int i = 0; i < adj.size(); i++)
    {
        if (!visited[adj[node][i]] && adj[node][i] == 1)
        {
            color[adj[node][i]] = color[node] == 1 ? 0 : 1;
            dfs(adj, visited, adj[node][i], color);
        }
    }
}

bool check(const vector<vector<int>> &adj, vector<bool> &visited, int node, vector<int> &color)
{
    visited[node] = true;
    for (int i = 0; i < adj.size(); i++)
    {
        if (!visited[adj[node][i]] && adj[node][i] == 1)
        {
            if (color[adj[node][i]] == color[node])
                return false;
            dfs(adj, visited, adj[node][i], color);
        }
    }
    return true;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adjl(n, vector<int>(n, 0));
    vector<bool> visited(n, false);
    vector<int> color(n, -1);

    int x, y;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        adjl[x][y] = 1;
        adjl[y][y] = 1;
    }

    color[0] = 1;
    dfs(adjl, visited, 0, color);

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    cout << check(adjl, visited, 0, color);
}