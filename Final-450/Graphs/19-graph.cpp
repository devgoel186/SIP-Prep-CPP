/* Prim's Algo - Here the idea is to construct MST by adding 
neighbors*/

/* TIME COMPLEXITY = O(E LOG V)
SPACE COMPLEXITY = O(E + V)*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void primsMST(int n, vector<bool> &visited, vector<vector<int>> &edges, vector<int> &distance, vector<int> &parent, int source)
{
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    distance[source] = 0;
    pq.push({0, source});
    while (!pq.empty())
    {
        vector<int> x = pq.top();
        pq.pop();
        int w = x[0];
        int u = x[1];
        int v = parent[x[1]];
        cout << u << " " << v << " " << w << endl;
        for (int i = 0; i < edges[u].size(); i++)
        {
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<vector<int>>> adjl(n);
    vector<bool> visited(n, false);
    vector<int> parent(n, 0);
    vector<int> distance(n, INT_MAX);

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjl[u].push_back({v, w});
        adjl[v].push_back({u, w});
    }

    distance[0] = 0;
}