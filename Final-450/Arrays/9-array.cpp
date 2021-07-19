// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// /* Complexity = O(n) */
// int getMinDiff(int *arr, int n, int k)
// {
//     sort(arr, arr + n);
//     if (arr[n - 1] < k)
//         return -1;
//     int maxEl = INT_MIN, minEl = INT_MAX;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] >= k)
//         {
//             maxEl = max(arr[n - 1] - k, arr[i] + k);
//             minEl = min(arr[0], arr[i + 1] - k);
//         }
//     }
//     return min()
// }

// int main()
// {
//     int n, k;
//     cin >> n >> k;
//     int *arr = new int[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     cout << getMinDiff(arr, n, k) << endl;

//     // for (int i = 0; i < n; i++)
//     // {
//     //     cout << arr[i] << " ";
//     // }
// }