#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool checkRotation(string s, string s2)
{
    if (s.size() != s2.size())
        return false;
    int i;
    for (i = 0; i < s.size(); i++)
    {
        if (s[i] == s2[0])
            break;
    }
    bool flag = 1;
    for (int j = 0; j < s.size(); j++)
    {
        if (s[(i + j) % s.size()] != s2[j])
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

int main()
{
    string s, s2;
    cin >> s >> s2;
    cout << checkRotation(s, s2) << endl;
}