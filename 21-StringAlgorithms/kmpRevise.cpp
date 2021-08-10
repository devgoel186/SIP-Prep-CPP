#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX INT_MAX

vector<int> prefix(string s)
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
    vector<int> pref = prefix(t);
    int index = 0;

    int i = 0, j = 0;
    while (i < t.size())
    {
        if (t[i] == s[j])
        {
            i++;
            j++;
        }

        else
        {
            if (j == 0)
                i++;
            else
                j = pref[j - 1];
        }

        if (j == s.size())
        {
            index = i - s.size();
            break;
        }
    }

    cout << "Found at " << index << endl;
}