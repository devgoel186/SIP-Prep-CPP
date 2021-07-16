#include <bits/stdc++.h>
using namespace std;
#define ll long long

void rotateMatrix(vector<vector<int>> &m)
{
    int n = m.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(m[i][j], m[j][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            swap(m[i][j], m[i][n - 1 - j]);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> m(n, vector<int>(n, 0));
    for (auto &i : m)
    {
        for (auto &j : i)
        {
            cin >> j;
        }
    }

    rotateMatrix(m);

    cout << endl;
    for (auto i : m)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}