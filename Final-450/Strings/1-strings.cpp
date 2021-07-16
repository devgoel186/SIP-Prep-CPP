#include <bits/stdc++.h>
using namespace std;
#define ll long long

void reverse(string &s)
{
    int i = 0, j = s.length() - 1;
    while (i < j)
    {
        swap(s[i], s[j]);
        i++;
        j--;
    }
}

int main()
{
    string s;
    cin >> s;
    reverse(s);
    cout << s << endl;
}