#include <bits/stdc++.h>
using namespace std;
#define ll long long

void powerSet(string s)
{
    for (int i = 0; i < (1 << s.length()); i++)
    {
        for (int j = 0; j < s.length(); j++)
        {
            if (i & (1 << j))
                cout << s[j];
        }
        cout << " ";
    }
}

int main()
{
    string s;
    cin >> s;
    powerSet(s);
}