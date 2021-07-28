#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX INT_MAX

int longestIncreasingSubsequence(vector<int> &arr, vector<int> &dp, int n)
{
    if (dp[n] != -1)
        return dp[n];

    dp[n] = 1;

    for (int i = 0; i < n; i++)
    {
        if (arr[n] > arr[i])
            dp[n] = max(dp[n], 1 + longestIncreasingSubsequence(arr, dp, i));
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (auto &i : arr)
        cin >> i;

    vector<int> dp(n, -1);

    cout << longestIncreasingSubsequence(arr, dp, n - 1);
}