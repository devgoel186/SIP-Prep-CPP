#include <bits/stdc++.h>
using namespace std;
#define ll long long

void BFS(vector<vector<int>> &adjl, vector<bool> &visited, int j)
{
    visited[j] = true;
    queue<int> q;
    q.push(j);

    while (!q.empty())
    {
        int node = q.front();
        cout << node << " ";
        q.pop();
        for (int i = 0; i < adjl[node].size(); i++)
        {
            if (!visited[adjl[node][i]])
            {
                visited[adjl[node][i]] = true;
                q.push(adjl[node][i]);
            }
        }
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
        adjl[y].push_back(x);
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            BFS(adjl, visited, i);
    }
}