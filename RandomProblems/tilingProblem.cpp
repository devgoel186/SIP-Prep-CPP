#include <bits/stdc++.h>
using namespace std;
#define ll long long

int tiling(int n)
{
    if (n == 0 || n == 1)
        return n;
    return tiling(n - 1) + tiling(n - 2);
}

int main()
{
    int n;
    cin >> n;
    cout << tiling(n) << endl;
}