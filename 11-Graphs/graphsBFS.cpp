#include <bits/stdc++.h>
using namespace std;
#define ll long long

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

    queue<int> q;
    q.push(1);
    visited[1] = true;

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