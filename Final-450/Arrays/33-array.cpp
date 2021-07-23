#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int count = 0;
    for (auto i : arr)
    {
        if (arr[i] <= k)
            count++;
    }

    int bad = 0;
    for (auto i : arr)
    {
        if (arr[i] > k)
            bad++;
    }

    int ans = bad;
    for (int i = 0, j = count; j < n; i++, j++)
    {
        if (arr[i] > k)
            bad--;
        if (arr[j] > k)
            bad++;
        ans = min(bad, ans);
    }

    cout << ans << endl;
}