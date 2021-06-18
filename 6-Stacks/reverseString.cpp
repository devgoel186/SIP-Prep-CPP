#include <iostream>
#include <stack>
using namespace std;

// TIME COMPLEXITY - O(N)
// SPACE COMPLEXITY - O(N)

void reverse(char *s, int n)
{
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        st.push(s[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << st.top();
        st.pop();
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    char *s = new char[n];
    cin >> s;
    reverse(s, n);
}