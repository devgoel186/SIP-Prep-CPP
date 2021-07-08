/* Catalan Numbers are a sequence ,
of natural numbers that occur in various counting problems,
often involving recursively defined objects. */

/* Their closed form is in terms of binomial coefficients,
C_n = (1 / (n + 1)) * (2n_C_n) = Sigma(C_i * C_n-i), i = 0 to n - 1
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

/* This implementation can obviously be improved, currently it is O(n!) */
ll catalanNth(ll n)
{
    if (n <= 1)
        return 1;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += catalanNth(i) * catalanNth(n - 1 - i);
    }
    return res;
}

int main()
{
    cout << catalanNth(9) << endl;
}

/* Application of Catalan Numbers
1. Possible BSTs
2. Paranthesis / Bracket Combinations
3. Possible Forests
4. Ways of triangulations
5. Possible paths in a matrix
6. Dividing a circle using N chords
7. Dyck words of given length & much more
*/