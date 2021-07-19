#include <bits/stdc++.h>
using namespace std;
#define ll long long

/* Complexity = O(n) */

int findMedian(int *arr1, int *arr2, int n)
{
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int *arr2 = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    findMedian(arr, arr2, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}