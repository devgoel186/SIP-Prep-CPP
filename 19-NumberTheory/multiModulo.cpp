#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX INT_MAX

/* The objective is to calculate B for the 
equation (A * B) % m = 1, where A and m and given */

struct triplet
{
    int gcd, x, y;
};

triplet extendedEuclid(int a, int b)
{
    if (b == 0)
    {
        triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }

    triplet smallAns = extendedEuclid(b, a % b);
    triplet ans;

    ans.gcd = smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a / b) * smallAns.y;
    return ans;
}

int multModuloInverse(int a, int m)
{
    /* 
    (A * B) % m = 1  [A and m are co-prime - their gcd is 1]
    => (A * B) is congruent to 1 (mod m)
    => (A * B - 1) is congruent to 0 (mod m)
    => (A * B - 1) = mq, where q is any integer
    => AB + mp = 1, where p = -q
    This converts to ax + by = gcd(a, b), and we just have to
    solve this eqn, and return x;
    */

    return extendedEuclid(a, m).x;
}

int main()
{
    int a, m;
    cin >> a >> m;

    cout << multModuloInverse(a, m) << endl;
}