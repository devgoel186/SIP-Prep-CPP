#include <bits/stdc++.h>
using namespace std;
#define ll long long

void DFS(vector<vector<int>> &adjl, vector<bool> &visited, int i)
{
    visited[i] = true;
    cout << i << " ";
    for (int j = 0; j < adjl[i].size(); j++)
    {
        if (!visited[adjl[i][j]])
            DFS(adjl, visited, adjl[i][j]);
    }
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
        // adjl[y].push_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            DFS(adjl, visited, i);
    }
}