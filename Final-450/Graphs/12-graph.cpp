#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<pair<int, int>>> adjl(n);
    vector<int> distance(n, INT_MAX);
    vector<bool> visited(n, false);

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
    s.insert({0, source}); /* {weight, vertex} */

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

    for (int i = 0; i < n; i++)
    {
        if (distance[i] < INT_MAX)
        {
            cout << i << " -> " << distance[i] << "\n";
        }
        else
            cout << i << " -> "
                 << "Not Reachable"
                 << "\n";
    }
}