#include <bits/stdc++.h>
using namespace std;
#define ll long long

/* Complexity = O(n) */
int kadanesAlgo(int *arr, int n)
{
    int sum = 0, prevSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > prevSum)
            prevSum = sum;
        if (sum < 0)
            sum = 0;
    }
    return prevSum;
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

    cout << "Max Subarray Sum = " << kadanesAlgo(arr, n);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
}