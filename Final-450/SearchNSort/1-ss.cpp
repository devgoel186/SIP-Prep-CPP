#include <bits/stdc++.h>
using namespace std;
#define ll long long

int first(int *arr, int n, int x)
{
    int l = 0, h = n - 1;
    int pos = -1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (x > arr[mid])
            l = mid + 1;
        else if (x < arr[mid])
            h = mid - 1;
        else
        {
            pos = mid;
            h = mid - 1;
        }
    }
    return pos;
}

int last(int *arr, int n, int x)
{
    int l = 0, h = n - 1;
    int pos = -1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (x > arr[mid])
            l = mid + 1;
        else if (x < arr[mid])
            h = mid - 1;
        else
        {
            pos = mid;
            l = mid + 1;
        }
    }
    return pos;
}

int main()
{
    int n, x;
    cin >> n >> x;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << first(arr, n, x) << " " << last(arr, n, x) << endl;
}