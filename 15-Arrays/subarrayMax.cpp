#include <bits/stdc++.h>
using namespace std;
#define ll long long

/* Kadane's Algorithm */
void printAllSubarrays(const vector<int> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = i; j < a.size(); j++)
        {
            for (int k = i; k <= j; k++)
            {
                printf("%d ", a[k]);
            }
            printf("%s", "\n");
        }
    }
}

int maxSubarray(const vector<int> &a)
{
    int prevMax = INT_MIN, max = 0;
    for (int i = 0; i < a.size(); i++)
    {
        max = max + a[i];
        if (prevMax < max)
            prevMax = max;
        if (max < 0)
            max = 0;
    }
    return prevMax;
}

// int maxSubarray2(const vector<int> &a)
// {
//     int prevMax = INT_MIN, max = 0;
//     for (int i = 0; i < a.size(); i++)
//     {
//         if (a[i] + max >= max)
//         {
//             max = a[i] + max;
//         }
//         else
//         {
//             max = a[i];
//         }
//         if (max > prevMax)
//             prevMax = max;
//     }
//     return prevMax;
// }

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;
    }
    cout << "Number of subarrays = " << n * (n + 1) / 2 << endl;
    printAllSubarrays(a);
    cout << maxSubarray(a) << endl;
    // cout << maxSubarray2(a) << endl;
}