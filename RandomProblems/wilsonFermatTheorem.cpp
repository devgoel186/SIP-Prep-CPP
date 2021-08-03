#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX INT_MAX

/* Fermat's Little Theorem - 
a^(p - 1) is congruent to 1 mod p. */

/* Wilson's Theorem -
(p - 1)! is congruent to (p - 1) mod p */

int power(int x, int y, int p)
{
    /* Finding x ^ y mod p using binary exponentiation */
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int modInverse(int a, int p)
{
    return power(a, p - 2, p);
}

int modFact(int n, int p)
{
    if (p <= n)
        return 0;
    int res = (p - 1);
    for (int i = n + 1; i < p; i++)
    {
        res = (res * modInverse(i, p)) % p;
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, p;
        cin >> n >> p;
        cout << modFact(n, p) << endl;
    }
}