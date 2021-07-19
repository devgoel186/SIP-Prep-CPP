#include <bits/stdc++.h>
using namespace std;
#define ll long long

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
}