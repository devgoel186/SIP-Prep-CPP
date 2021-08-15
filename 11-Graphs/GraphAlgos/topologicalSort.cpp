#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX INT_MAX

vector<int> topoSort(vector<vector<int>> adjl)
{
    vector<int> indegree(adjl.size(), 0);

    for (int i = 0; i < adjl.size(); i++)
    {
        for (int j = 0; j < adjl[i].size(); j++)
        {
            indegree[adjl[i][j]]++;
        }
    }

    queue<int> q;
    vector<int> ans;

    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        ans.push_back(top);

        for (auto i : adjl[top])
        {
            indegree[i]--;
            if (indegree[i] == 0)
                q.push(i);
        }
    }

    return ans;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adjl(n);

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adjl[u].push_back(v);
    }

    vector<int> ans = topoSort(adjl);

    for (auto i : ans)
        cout << i << " ";
    cout << endl;
}