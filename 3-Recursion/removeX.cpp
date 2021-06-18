#include <iostream>
#include <string>
using namespace std;

void removeX(char *s)
{
    if (s[0] == '\0')
        return;
    if (s[0] == 'x')
    {
        int i;
        for (i = 1; s[i] != '\0'; i++)
        {
            s[i - 1] = s[i];
        }
        s[i - 1] = s[i];
        removeX(s);
    }
    else
    {
        removeX(s + 1);
    }
}

int main()
{
    int n;
    cin >> n;
    char *s = new char[n];
    cin >> s;
    removeX(s);
    cout << s << endl;
}