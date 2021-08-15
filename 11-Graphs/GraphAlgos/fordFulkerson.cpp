/* Also called as Edmund-Karp Algorithm, as Edmund Karp introduced an optimization */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX INT_MAX

bool bfs(vector<vector<int>> &graph, vector<int> &parent, int src, int sink)
{
    vector<bool> visited(graph.size(), false);

    queue<int> q;
    visited[src] = true;
    q.push(src);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < graph.size(); v++)
        {
            if (!visited[v] && graph[u][v] > 0)
            {
                if (v == sink)
                {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return false;
}

int fordFulkerson(vector<vector<int>> &graph, int src, int sink)
{
    vector<int> parent(graph.size(), -1);

    /* Residual graph for storing residual paths */
    vector<vector<int>> residualGraph = graph;

    /* No flow initially */
    int maxFlow = 0;

    while (bfs(residualGraph, parent, src, sink))
    {
        int pathFlow = INT_MAX;

        for (int v = sink; v != src; v = parent[v])
        {
            int u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }

        for (int v = sink; v != src; v = parent[v])
        {
            int u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adjm(n, vector<int>(n, 0));

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjm[u][v] = w;
    }

    int src, sink;
    cin >> src >> sink;

    cout << fordFulkerson(adjm, src, sink) << endl;
}