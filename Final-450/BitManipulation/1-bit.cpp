#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;
    int x = 1;
    int count = 0;

    while (x <= n)
    {
        bool out = ((x & n) != 0);
        count = count + out;
        x = x << 1;
    }

    cout << count << endl;
}