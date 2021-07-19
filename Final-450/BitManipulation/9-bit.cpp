#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;

    int times = n, result = 0;
    while (times != 0)
    {
        int curr = 1, possibleShift = 0;
        while ((curr << 1) <= times)
        {
            curr = curr << 1;
            possibleShift++;
        }
        result += (n << possibleShift);
        times -= curr;
    }
    cout << result << endl;
}