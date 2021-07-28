#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX INT_MAX

int calculateKnapsack(vector<int> &values, vector<int> &weights, int n, int W)
{
    vector<int> dp(W + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = W; j >= 0; j--)
        {
            if (weights[i - 1] <= j)
            {
                dp[j] = max(dp[j], dp[j - weights[i - 1]] + values[i - 1]);
            }
        }
    }

    return dp[W];
}

int main()
{
    int n;
    cin >> n;
    vector<int> values(n, 0);
    for (auto &i : values)
        cin >> i;

    vector<int> weights(n, 0);
    for (auto &i : weights)
        cin >> i;

    int W;
    cin >> W;

    cout << calculateKnapsack(values, weights, n, W);
}