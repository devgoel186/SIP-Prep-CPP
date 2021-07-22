#include <bits/stdc++.h>
using namespace std;
#define ll long long

int precedence(char s)
{
    if (s == '^')
        return 3;
    else if (s == '*' || s == '/')
        return 2;
    else if (s == '+' || s == '-')
        return 1;
    return -1;
}

int main()
{
    string s;
    cin >> s;
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            cout << s[i];
        else
        {
            if (s[i] == '(')
                st.push(s[i]);
            else if (s[i] == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    cout << st.top();
                    st.pop();
                }
                if (!st.empty())
                    st.pop();
            }
            else
            {
                while (!st.empty() && (precedence(s[i]) <= precedence(st.top())))
                {
                    cout << st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
    }
    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
}