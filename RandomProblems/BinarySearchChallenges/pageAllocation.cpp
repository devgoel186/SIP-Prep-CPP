#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isFeasible(int *arr, int mid, int n, int m)
{
    int sum = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
        {
            return false;
        }
        if (sum + arr[i] > mid)
        {
            count++;
            sum = arr[i];
            if (count > m)
            {
                return false;
            }
        }
        else
            sum += arr[i];
    }
    return true;
}

int minPages(int *arr, int n, int m)
{
    int maxSum = 0;
    if (n < m)
        return -1;

    for (int i = 0; i < n; i++)
    {
        maxSum += arr[i];
    }

    int result = INT_MAX;
    int left = 0, right = maxSum;

    while (left < right)
    {
        int mid = (left + right) / 2;
        if (isFeasible(arr, mid, n, m))
        {
            result = min(result, mid);
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return result;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << minPages(arr, n, m) << endl;
}