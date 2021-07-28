#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX INT_MAX

/*
COMPLEXITY = O(m * n)
SPACE COMPLEXITY = O(n)
*/

int main()
{
    int n; /* n is the value to achieve */
    cin >> n;
    vector<int> res(n + 1, 0);
    res[0] = 1;

    int m; /* m is the number of coins available */
    cin >> m;
    vector<int> values(m, 0);
    for (auto &i : values)
        cin >> i;

    for (int i = 0; i < m; i++)
    {
        for (int j = values[i]; j <= n; j++)
        {
            res[j] = res[j] + res[j - values[i]];
        }
    }

    cout << res[n] << endl;
}