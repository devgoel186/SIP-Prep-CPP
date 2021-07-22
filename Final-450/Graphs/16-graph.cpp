#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF INT_MAX

/* TIME - COMPLEXITY = O(V^3) */

int main()
{
    vector<vector<int>> adjm;

    adjm = {{0, 5, INF, 10},
            {INF, 0, 3, INF},
            {INF, INF, 0, 1},
            {INF, INF, INF, 0}};
    int n = adjm.size();
    vector<vector<int>> distance = adjm;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (distance[i][k] != INF && distance[k][j] != INF && distance[i][k] + distance[k][j] < distance[i][j])
                    distance[i][j] = distance[i][k] + distance[k][j];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (distance[i][j] == INF)
                cout << "INF ";
            else
                cout << distance[i][j] << " ";
        }
        cout << endl;
    }
}