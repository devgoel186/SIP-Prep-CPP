#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool powerOf2(int n)
{
    int temp = 1;
    while (temp <= n)
    {
        if (temp == n)
            return true;
        temp = temp << 1;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    cout << powerOf2(n) << endl;
}