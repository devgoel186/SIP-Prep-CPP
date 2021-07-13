#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isBipartite(const vector<vector<int>> &adj, vector<bool> &visited, int node, vector<int> &color)
{
    visited[node] = true;
    for (int i = 0; i < adj.size(); i++)
    {
        if (i == node)
            continue;
        if (adj[node][i] == 1)
        {
            if (!visited[i])
            {
                color[i] = color[node] xor 1;
                if (!isBipartite(adj, visited, i, color))
                    return false;
            }
            else if (color[i] == color[node])
                return false;
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
        adjl[y][x] = 1;
    }

    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            color[i] = 0;
            if (!isBipartite(adjl, visited, i, color))
            {
                flag = true;
                break;
            }
        }
    }

    flag ? cout << "Not Bipartite" << endl : cout << "Bipartite" << endl;

    for (auto i : color)
    {
        cout << i << " ";
    }
    cout << endl;
}