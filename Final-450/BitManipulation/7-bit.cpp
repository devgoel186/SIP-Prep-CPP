#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int x, y, l, r;
    cin >> x >> y;
    cin >> l >> r;

    for (int i = l; i <= r; i++)
    {
        if (y & (1 << (i - 1)))
            x = x | (1 << (i - 1));
    }

    cout << x << endl;
}