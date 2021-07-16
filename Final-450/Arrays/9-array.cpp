#include <bits/stdc++.h>
using namespace std;
#define ll long long

/* Complexity = O(n) */
int getMinDiff(int *arr, int n, int k)
{
    sort(arr, arr + n);
    int mid = (arr[0] + arr[n - 1]) / 2;
    if (k <= mid)
    {
        for (int i = 0; i < n; i++)
        {
        }
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << getMinDiff(arr, n, k) << endl;

    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
}