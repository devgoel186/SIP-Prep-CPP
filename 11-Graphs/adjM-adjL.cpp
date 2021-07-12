#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adjm(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> adjl(n + 1);

    int x, y;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y;
        adjm[x][y] = 1;
        adjm[y][x] = 1;
    }

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cout << adjm[i][j] << " ";
        }
        cout << endl;
    }

    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;

        adjl[x].push_back(y);
        adjl[y].push_back(x);
    }

    for (int i = 0; i < n + 1; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < adjl[i].size(); j++)
        {
            cout << adjl[i][j] << " ";
        }
        cout << endl;
    }
}