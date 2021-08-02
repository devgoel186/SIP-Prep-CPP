#include <bits/stdc++.h>
using namespace std;
#define long long ll
#define MAX INT_MAX
#define MOD 1000000007

vector<int> dijkstraBFS(vector<vector<pair<int, int>>> graph, int src)
{
    vector<int> distance(graph.size(), INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    distance[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (auto i : graph[u])
        {
            int v = i.first;
            int w = i.second;

            if (distance[v] > distance[u] + w)
            {
                distance[v] = distance[u] + w;
                pq.push({distance[v], v});
            }
        }
    }

    return distance;
}

vector<int> dijkstraDFS(vector<vector<pair<int, int>>> graph, int src)
{
    vector<int> distance(graph.size(), INT_MAX);
    set<pair<int, int>> s;
    s.insert({0, src});
    distance[src] = 0;

    while (!s.empty())
    {
        auto x = *(s.begin()); /* weight, vertex */
        s.erase(x);
        for (auto i : graph[x.second]) /* vertex, weight */
        {
            if (distance[i.first] > distance[x.second] + i.second)
            {
                s.erase({distance[i.first], i.first});
                distance[i.first] = distance[x.second] + i.second;
                s.insert({distance[i.first], i.first});
            }
        }
    }

    return distance;
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<pair<int, int>>> adjl(n);
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adjl[u].push_back({v, w});
        adjl[v].push_back({u, w});
    }

    vector<int> distance = dijkstraBFS(adjl, 0);
    vector<int> distance2 = dijkstraDFS(adjl, 0);

    for (auto i : distance)
    {
        cout << i << " ";
    }
    cout << endl;

    for (auto i : distance2)
    {
        cout << i << " ";
    }
    cout << endl;
}