#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool palindrome(string s)
{
    int i = 0, j = s.length() - 1;
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

int main()
{
    string s;
    cin >> s;
    cout << palindrome(s) << endl;
}