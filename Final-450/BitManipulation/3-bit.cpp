#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int a, b;
    cin >> a >> b;
    int xorsum = a ^ b;
    int temp = 1;
    int count = 0;
    while (temp <= xorsum)
    {
        count += (temp & xorsum) != 0;
        temp = temp << 1;
    }

    cout << count << endl;
}