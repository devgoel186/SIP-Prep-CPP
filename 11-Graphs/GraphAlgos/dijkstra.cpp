#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF INT_MAX

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<pair<int, int>>> adjl(n);
    vector<bool> visited(n, false);
    vector<int> distance(n, INF);

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjl[u].push_back({v, w});
        adjl[v].push_back({u, w});
    }

    int source;
    cin >> source;
    distance[source] = 0;

    set<pair<int, int>> s;
    s.insert({0, source});
    while (!s.empty())
    {
        pair<int, int> x = *(s.begin());
        s.erase(x);
        for (auto it : adjl[x.second])
        {
            if (distance[it.first] > distance[x.second] + it.second)
            {
                s.erase({distance[it.first], it.first});
                distance[it.first] = distance[x.second] + it.second;
                s.insert({distance[it.first], it.first});
            }
        }
    }

    for (auto it : distance)
    {
        if (it == INF)
            cout << "INF ";
        else
            cout << it << " ";
    }
}