#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;
    int shift = 0;
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i >= (1 << shift))
        {
            shift++;
        }
        sum = ((i % 1000000007) + ((sum << shift) % 1000000007)) % 1000000007;
    }

    cout << sum << endl;
}