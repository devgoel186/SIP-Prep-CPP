#include <bits/stdc++.h>
using namespace std;
#define ll long long

/* Complexity = O(n) */

bool compare(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        arr[i] = vector<int>({start, end});
    }

    sort(arr.begin(), arr.end());

    vector<vector<int>> res;

    int i = 0;
    for (i = 0; i < n - 1; i++)
    {
        int start1 = arr[i][0];
        int end1 = arr[i][1];

        while (i < n - 1 && end1 >= arr[i + 1][0])
        {
            if (end1 >= arr[i + 1][1])
            {
                i++;
                continue;
            }
            end1 = arr[i + 1][1];
            i++;
        }

        res.push_back({start1, end1});
    }

    if (i == n - 1)
        res.push_back({arr[n - 1][0], arr[n - 1][1]});

    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}