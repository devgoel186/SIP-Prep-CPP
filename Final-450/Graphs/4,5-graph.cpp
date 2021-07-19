#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool detectCycle(vector<vector<int>> &adjl, vector<bool> visited, int node, int parent)
{
    visited[node] = true;
    for (int i = 0; i < adjl[node].size(); i++)
    {
        if (visited[adjl[node][i]] && adjl[node][i] != parent)
            return true;
        else if (!visited[adjl[node][i]] && adjl[node][i] != parent)
            return detectCycle(adjl, visited, adjl[node][i], node);
    }
    return false;
}

bool detectCycleDirected()
{
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adjl(n);
    vector<bool> visited(n, false);

    int x, y;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        adjl[x].push_back(y);
        adjl[y].push_back(x);
    }

    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            flag = detectCycle(adjl, visited, i, i);
        }
    }

    cout << flag << endl;
}