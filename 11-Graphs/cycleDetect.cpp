#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool cycleDetect(int node, const vector<vector<int>> &adj, vector<bool> &visited, int parent)
{
    visited[node] = true;

    for (int i = 0; i < adj[node].size(); i++)
    {
        if (visited[adj[node][i]] && adj[node][i] != parent)
        {
            return true;
        }
        else if (!visited[adj[node][i]] && adj[node][i] != parent)
        {
            return cycleDetect(adj[node][i], adj, visited, node);
        }
    }
    return false;
}

bool cycleDetectDirected(int node, const vector<vector<int>> &adj, vector<bool> &visited, vector<int> &stack)
{
    stack[node] = true;
    if (!visited[node])
    {
        visited[node] = true;
        for (int i = 0; i < adj[node].size(); i++)
        {
            if (stack[adj[node][i]])
                return true;
            if (!visited[adj[node][i]])
                return cycleDetectDirected(adj[node][i], adj, visited, stack);
        }
    }
    stack[node] = false;
    return false;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adjl(n);
    vector<bool> visited(n, false);
    vector<int> stack(n, 0);
    int x, y;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        adjl[x].push_back(y);
        // adjl[y].push_back(x);
    }

    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && cycleDetectDirected(i, adjl, visited, stack))
        {
            flag = 1;
            break;
        }
    }

    switch (flag)
    {
    case 1:
        cout << "Cycle Present" << endl;
        break;
    default:
        cout << "No Cycle Exists" << endl;
    }
}