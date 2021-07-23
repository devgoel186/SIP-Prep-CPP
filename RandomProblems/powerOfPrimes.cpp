#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long factorial(long long n)
{
}

int main()
{
    int n;
    cin >> n;
    map<long long, long long> m;

    while (n % 2 == 0)
    {
        m[2]++;
        n /= 2;
    }

    for (long long i = 3; i < sqrt(n); i += 2)
    {
        while (n % i == 0 && n != 0)
        {
            m[i]++;
            n /= i;
        }
    }

    vector<long long> res;

    for (auto it : m)
    {
        res.push_back(it.second);
    }

    for (auto it : res)
    {
        cout << it << " ";
    }
}