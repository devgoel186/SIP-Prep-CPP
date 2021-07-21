#include <bits/stdc++.h>
using namespace std;
#define ll long long

int precedence(char s)
{
    if (s == '^')
        return 1;
    if (s == '*' || s == '/')
        return 2;
    else if (s == '+' || s == '-')
        return 3;
    return -1;
}

int main()
{
    string s;
    cin >> s;
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
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
                while (!st.empty() && (precedence(s[i]) < precedence(st.top())))
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