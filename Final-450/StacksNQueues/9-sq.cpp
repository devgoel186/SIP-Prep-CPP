// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// vector<long long> nextLargerElement(vector<long long> arr, int n)
// {
//     long long currMax = arr[n - 1];
//     stack<int> s;
//     s.push(-1);
//     for (long long i = n - 1; i >= 1; i--)
//     {
//         if (arr[i - 1] > currMax)
//         {
//             currMax = arr[i - 1];
//             s.push(-1);
//         }
//         else if (arr[i] > arr[i - 1])
//             s.push(arr[i]);
//         else
//             s.push(s.top());
//     }
//     vector<long long> res;
//     while (!s.empty())
//     {
//         res.push_back(s.top());
//         s.pop();
//     }
//     return res;
// }

// int main()
// {
//     int n;
//     cin >> n;
//     vector<long long> arr(n);
//     for (auto &i : arr)
//     {
//         cin >> i;
//     }
//     vector<long long> res = nextLargerElement(arr, n);

//     // while (!s.empty())
//     // {
//     //     cout << s.top() << " ";
//     //     s.pop();
//     // }

//     for (auto it : res)
//     {
//         cout << it << " ";
//     }
// }