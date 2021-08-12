#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX INT_MAX

void bfs(vector<vector<int>> &adjl, vector<int> &visited, int src)
{
    visited[src] = true;
    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        cout << top << " ";

        for (auto i : adjl[top])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
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

    bfs(adjl, visited, 0);
}