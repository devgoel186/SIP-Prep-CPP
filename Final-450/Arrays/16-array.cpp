#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr)
        cin >> i;

    multiset<int> set1;
    set1.insert(arr[0]);
    multiset<int>::iterator it;
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        set1.insert(arr[i]);
        it = set1.upper_bound(arr[i]);
        count += distance(it, set1.end());
    }

    cout << count << endl;
}