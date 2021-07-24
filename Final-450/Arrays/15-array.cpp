#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int main()
{
    int n;
    cin >> n;
    vector<int> arr({1, 2, 3});
    vector<int> res;
    next_permutation(arr.begin(), arr.end());
    for (auto i : arr)
    {
        cout << i << " ";
    }
}