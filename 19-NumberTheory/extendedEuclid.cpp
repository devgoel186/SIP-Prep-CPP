/* Diophantine euqations are polynomial eqs for which solns. exist */
/* Solutions to these exist only if gcd(a, b) divides c */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX INT_MAX

struct triplet
{
    int x, y, gcd;
};

/* ax + by = gcd(a, b)
gcd(a, b) = gcd(b, a % b)
gcd(b, a % b) = bx_1 + (a % b)y_1
a%b = a - (a/b)*b

From above, we get

ax + by = bx_1 + (a % b)y_1
ax + by = bx_1 + (a - (a/b)*b)y_1
ax + by = ay_1 + b(x_1 - (a/b)y_1)

Therefore, x = y_1 ; y = x_1 - (a/b)y_1
*/

triplet extendedEuclid(int a, int b)
{
    if (b == 0) /* case for ax + by = gcd(a, b) where b = 0 */
    {
        triplet ans;
        ans.x = 1;
        ans.gcd = a;
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

int main()
{
    int a, b;
    cin >> a >> b;

    triplet ans = extendedEuclid(a, b);
    cout << ans.gcd << " " << ans.x << " " << ans.y << endl;
}