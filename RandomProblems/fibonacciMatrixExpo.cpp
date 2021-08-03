/* Finbonacci in O(log n) using matrix exponentiation */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX INT_MAX

vector<vector<int>> multiplyVector(vector<vector<int>> a, vector<vector<int>> b)
{
    int n = a.size();
    vector<vector<int>> ans(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                ans[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return ans;
}

vector<vector<int>> matrixExponentiate(vector<vector<int>> &a, int n)
{
    if (n == 0)
    {
        vector<vector<int>> ans(a.size(), vector<int>(a.size(), 0));
        for (int i = 0; i < a.size(); i++)
        {
            ans[i][i] = 1;
        }
        return ans;
    }

    if (n == 1)
        return a;

    vector<vector<int>> temp = matrixExponentiate(a, n / 2);
    vector<vector<int>> ans = multiplyVector(temp, temp);
    if (n & 1)
        ans = multiplyVector(ans, a);

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> a = {{1, 1}, {1, 0}};
    vector<vector<int>> ans = matrixExponentiate(a, n);

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}