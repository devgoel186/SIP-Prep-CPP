#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;
    ceil(log2(n)) == floor(log2(n)) ? cout << log2(n) : cout << -1;
}