#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX INT_MAX

int minSquare(vector<int> &dp, int n)
{
    if (n >= 0 && n <= 3)
        return n;

    if (dp[n] != MAX)
    {
        return dp[n];
    }

    for (int i = 1; i * i <= n; i++)
    {
        dp[n] = min(dp[n], 1 + minSquare(dp, n - i * i));
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, MAX);

    cout << minSquare(dp, n) << endl;
}