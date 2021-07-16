#include <bits/stdc++.h>
using namespace std;
#define ll long long

/* Complexity = O(n) */

void rotate(int *arr, int n)
{
    int i = 0, j = n - 1;
    for (int k = 0; k < n - 1; k++)
    {
        swap(arr[i], arr[j]);
        i++;
    }
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

    rotate(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}