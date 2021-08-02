#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX INT_MAX

int power(int a, int n)
{
    if (n == 0)
        return 1;

    int p = (power(a, n / 2) % MOD);
    if (n & 1)
        return (((p * p) % MOD) * a) % MOD;
    else
        return (p * p) % MOD;
}

int main()
{
    int a, n;
    cin >> a >> n;

    cout << power(a % MOD, n) << endl;
}