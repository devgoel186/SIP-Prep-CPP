#include <bits/stdc++.h>
using namespace std;
#define long long ll
#define MAX INT_MAX
#define MOD 1000000007

void dfs(vector<vector<int>> &graph, vector<int> &visited, int node)
{
    visited[node] = true;
    cout << node << " ";

    for (auto i : graph[node])
    {
        if (!visited[i])
            dfs(graph, visited, i);
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
        int x, y;
        cin >> x >> y;
        adjl[x].push_back(y);
        adjl[y].push_back(x);
    }

    dfs(adjl, visited, 0);
    cout << endl;
}