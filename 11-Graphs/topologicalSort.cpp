#include <bits/stdc++.h>
using namespace std;
#define ll long long

/* Only DAG have a topological sort */

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adjl(n);
    vector<int> indegree(n, 0);

    int x, y;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        adjl[x].push_back(y);
        indegree[y]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for (int i = 0; i < adjl[node].size(); i++)
        {
            cout << "a ";
            indegree[adjl[node][i]]--;
            if (indegree[adjl[node][i]] == 0)
                q.push(adjl[node][i]);
        }
    }
}