#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX INT_MAX

int lcs(vector<vector<int>> &dp, string s1, string s2, int n, int m)
{
    if (n == 0 || m == 0)
    {
        // dp[n][m] = 0;
        // return dp[n][m];
        return 0;
    }

    if (dp[n][m] != -1)
        return dp[n][m];

    if (s1[n - 1] == s2[m - 1])
        dp[n][m] = 1 + lcs(dp, s1, s2, n - 1, m - 1);
    else
        dp[n][m] = max(lcs(dp, s1, s2, n, m - 1), lcs(dp, s1, s2, n - 1, m));

    return dp[n][m];
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << lcs(dp, s1, s2, n, m) << endl;
}