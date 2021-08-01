/* Articulation points are those points in a graph which when removed, 
increase the number of connected components in the graph */

/* To detect articulation points, we use tarjan's algo */

#include <bits/stdc++.h>
using namespace std;
#define long long ll
#define MAX INT_MAX
#define MOD 1000000007

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
        adjl[y].push_back(x);
    }
}