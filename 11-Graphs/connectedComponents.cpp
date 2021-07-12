#include <bits/stdc++.h>
using namespace std;
#define ll long long

int traverseComponent(const vector<vector<int>> &adj, vector<bool> &visited, int node)
{
    visited[node] = true;
    // cout << node << " ";
    int sum = 1;

    for (int i = 0; i < adj[node].size(); i++)
    {
        if (!visited[adj[node][i]])
        {
            sum += traverseComponent(adj, visited, adj[node][i]);
        }
    }

    return sum;
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

    vector<int> sizes;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            sizes.push_back(traverseComponent(adjl, visited, i));
            count++;
        }
    }

    cout << "Number of Connected Components : " << count << "\nSizes : ";
    for (auto i : sizes)
    {
        cout << i << " ";
    }
}