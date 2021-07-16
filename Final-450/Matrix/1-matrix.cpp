#include <bits/stdc++.h>
using namespace std;
#define ll long long

void spiralTraverse(vector<vector<int>> m)
{
    bool ltr = true;
    int i = 0, j = 0;
    while (i < m.size())
    {
        if (j == m.size())
        {
            j--;
            i++;
            ltr = !ltr;
            cout << endl;
            continue;
        }
        if (j == -1)
        {
            j++;
            i++;
            ltr = !ltr;
            cout << endl;
            continue;
        }

        cout << m[i][j] << " ";

        if (ltr)
            j++;
        else
            j--;
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

    cout << "\n\nSPIRAL\n";
    spiralTraverse(m);
}