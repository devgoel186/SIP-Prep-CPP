#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> mergeKArrays(vector<vector<int>> &arr, int k)
{
    vector<int> index(k, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
    for (int i = 0; i < k; i++)
    {
        minheap.push(make_pair(arr[i][0], i));
    }
    vector<int> res;
    while (!minheap.empty())
    {
        pair<int, int> temp = minheap.top();
        int el = temp.first;
        int i = temp.second;
        minheap.pop();
        res.push_back(el);
        if (index[i] + 1 < arr[i].size())
            minheap.push(make_pair(arr[i][index[i] + 1], i));
        index[i]++;
    }

    return res;
}

int main()
{
    int k;
    cin >> k;
    vector<vector<int>> arr(k);
    for (int i = 0; i < k; i++)
    {
        int n;
        cin >> n;
        arr[i] = vector<int>(n);
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<int> res = mergeKArrays(arr, k);

    for (auto i : res)
    {
        cout << i << " ";
    }
}