#include <bits/stdc++.h>
using namespace std;
#define ll long long

/* Complexity = O(n) */

int duplicate(int *arr)
{
    int i = 0;
    while (arr[i] > 0)
    {
        arr[i] = -arr[i];
        i = abs(arr[i]);
    }
    return abs(i);
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        cin >> arr[i];
    }

    cout << duplicate(arr) << endl;

    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
}