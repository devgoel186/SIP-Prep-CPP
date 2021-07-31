#include <bits/stdc++.h>
using namespace std;
#define long long ll
#define MAX INT_MAX
#define MOD 1000000007

vector<int> topologicalSort(vector<vector<int>> graph)
{
    queue<int> q;
    vector<int> indegree(graph.size(), 0);
    vector<int> res;

    for (auto i : graph)
    {
        for (auto j : i)
        {
            indegree[j]++;
        }
    }

    for (int i = 0; i < graph.size(); i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        res.push_back(front);
        for (auto i : graph[front])
        {
            indegree[i]--;
            if (indegree[i] == 0)
                q.push(i);
        }
    }

    return res;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adjl(n);
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adjl[x].push_back(y);
    }

    vector<int> res = topologicalSort(adjl);
    for (auto i : res)
    {
        cout << i << " ";
    }
}