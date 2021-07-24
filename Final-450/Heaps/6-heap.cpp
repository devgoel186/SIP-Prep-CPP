#include <bits/stdc++.h>
using namespace std;
#define long long ll;

int main()
{
    int k;
    vector<vector<int>> arr;
    for (int i = 0; i < k; i++)
    {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }
        arr.push_back(a);
    }
}