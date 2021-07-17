#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;
    int *start = new int[n];
    int *end = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> start[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> end[i];
    }

    int count = 0;
    int endEl = end[0];
    for (int i = 0; i < n; i++)
    {
        if (start[i] >= endEl)
        {
            count++;
            endEl = end[i];
        }
    }

    cout << "Count = " << count + 1 << endl;
}