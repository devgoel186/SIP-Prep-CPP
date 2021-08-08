/* KMP - Knuth Morris Pratt */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX INT_MAX

// Time complexity = O(n), where n is length of string */
vector<int> prefixFunction(string s)
{
    int n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];

        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main()
{
    string t, s;
    cin >> t >> s;
    vector<int> res = prefixFunction(t);
    // for (auto i : res)
    //     cout << i << " ";

    int pos = -1;
    int i = 0, j = 0;
    while (i < t.size())
    {
        if (t[i] == s[j]) /* If similar, proceed further */
        {
            i++;
            j++;
        }
        /* If not similar, go back to the last index, which indicates 
        how much of substring we matched successfully */
        else
        {
            if (j == 0)
                i++;
            else
                j = res[j - 1];
        }

        if (j == s.size())
        {
            pos = i - s.size();
            break;
        }
    }

    cout << pos << endl;
}