#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

/* Complexity = O(n) */

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int i, res = 0;
    int localMin, localMax;
    int globalMax = INT_MIN;
    while (i < n - 1)
    {
        while (i < n - 1 && arr[i] <= arr[i + 1])
            i++;
        localMin = i - 1;

        if (i == n - 1)
            break;

        while (i < n - 1 && arr[i] >= arr[i + 1])
            i++;
        localMax = i - 1;

        res = localMax - localMin;
        if (res > globalMax)
            globalMax = res;
    }
}