#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX INT_MAX

int main()
{
    string t, s;
    cin >> t >> s;

    int tl = t.length(), sl = s.length();

    for (int i = 0; i < tl - sl + 1; i++)
    {
        if (t.substr(i, s.length()) == s)
            cout << "Found" << endl;
    }
}