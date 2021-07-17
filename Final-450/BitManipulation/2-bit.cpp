#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<int, int> nonRepeating(int *arr, int n)
{
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        a = a xor arr[i];
    }

    int p = 0, q = 0;
    int rightMostSetBit = a & ~(a - 1);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & rightMostSetBit)
            p = p xor arr[i];
        else
            q = q xor arr[i];
    }
    return make_pair(p, q);
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

    pair<int, int> res = nonRepeating(arr, n);

    cout << res.first << " " << res.second << endl;
}