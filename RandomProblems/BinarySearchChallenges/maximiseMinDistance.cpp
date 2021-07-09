#include <bits/stdc++.h>
using namespace std;
#define ll long long

int isFeasible(int mid, int *arr, int n, int k)
{
    int pos = arr[0];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - pos >= mid)
        {
            pos = arr[i];
            count++;
            if (count == k)
                return true;
        }
    }
    return false;
}

int findDistance(int *arr, int n, int k)
{
    sort(arr, arr + n);
    int result = -1;
    int left = 1, right = arr[n - 1];
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (isFeasible(mid, arr, n, k))
        {
            result = max(result, mid);
            left = mid + 1;
        }
        else
            right = mid + 1;
    }
    return result;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Largest Minimum Distance : " << findDistance(arr, n, k) << endl;
}