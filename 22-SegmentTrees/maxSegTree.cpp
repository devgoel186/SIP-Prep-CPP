#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX INT_MAX

void build(const vector<int> &arr, vector<int> &tree, int node, int st, int en)
{
    if (st == en)
    {
        tree[node] = arr[st];
        return;
    }

    int mid = (st + en) / 2;
    build(arr, tree, 2 * node, st, mid);
    build(arr, tree, (2 * node) + 1, mid + 1, en);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

int queryMax(vector<int> &tree, int node, int st, int en, int l, int r)
{
    if (st > r || en < l)
        return INT_MIN;
    else if (st >= l && en <= r)
        return tree[node];

    int mid = (st + en) / 2;
    int q1 = queryMax(tree, 2 * node, st, mid, l, r);
    int q2 = queryMax(tree, 2 * node + 1, mid + 1, en, l, r);

    return max(q1, q2);
}

void update(vector<int> &arr, vector<int> &tree, int node, int st, int en, int index, int val)
{
    if (st == en)
    {
        arr[st] = val;
        tree[node] = val;
        return;
    }

    int mid = (st + en) / 2;
    if (index <= mid)
        update(arr, tree, 2 * node, st, mid, index, val);
    else
        update(arr, tree, 2 * node + 1, mid + 1, en, index, val);

    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n, 0), tree(2 * n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    build(arr, tree, 1, 0, n - 1);

    while (1)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            int ans = queryMax(tree, 1, 0, n - 1, l, r);
            cout << ans << endl;
        }
        else if (type == 2)
        {
            int index, val;
            cin >> index >> val;
            update(arr, tree, 1, 0, n - 1, index, val);
            cout << queryMax(tree, 1, 0, n - 1, 0, n - 1) << endl;
        }
        else
            break;
    }
}