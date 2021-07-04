#include <iostream>
#include <string>
using namespace std;

void allSubstrings(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char ch = s[0];
    string res = s.substr(1);
    allSubstrings(res, ans);
    allSubstrings(res, ans + ch);
}

int main()
{
    string s;
    cin >> s;
    allSubstrings(s, "");
}