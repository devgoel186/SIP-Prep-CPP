#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool powerOf2(ll n)
{
    ll temp = 1;
    while (temp <= n)
    {
        if (temp == n)
            return true;
        temp = temp << 1;
    }
    return false;
}

bool powerOf2Optimised(ll n)
{
    return n && ((n & (n - 1)) == 0);
}

int main()
{
    ll n;
    cin >> n;
    cout << powerOf2Optimised(n) << endl;
    cout << powerOf2(n) << endl;
}