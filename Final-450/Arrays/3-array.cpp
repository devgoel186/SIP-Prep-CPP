#include <bits/stdc++.h>
using namespace std;
#define ll long long

/* Complexity = O(n) */

// TODO

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int i = 0, j = n - 1;
    while (i < j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }

    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}