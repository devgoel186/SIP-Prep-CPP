#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second > p2.second;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        if (freq.find(arr[i]) != freq.end())
            freq[arr[i]]++;
        else
            freq.insert(make_pair(arr[i], 0));
    }
    vector<pair<int, int>> values(freq.begin(), freq.end());
    sort(values.begin(), values.end(), compare);

    for (int i = 0; i < k; i++)
    {
        cout << values[i].first << " ";
    }
}

/* Complexity = O(d log d), where d is the number of distinct elements in the array.*/
/* Because d is the number of elements we have in values array, and sorting is O(n log n) */