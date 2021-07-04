#include <iostream>
#include <string>
using namespace std;

void permute(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        string res = s.substr(0, i) + s.substr(i + 1);
        permute(res, ans + ch);
    }
}

int main()
{
    string s = "ABC";
    permute(s, "");
}