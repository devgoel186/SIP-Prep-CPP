#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX INT_MAX

void build(const vector<int> &arr, vector<pair<int, int>> &tree, int node, int st, int en)
{
    if (st == en)
    {
        tree[node].first = arr[st];
        tree[node].second = 1;
        return;
    }

    int mid = (st + en) / 2;
    build(arr, tree, 2 * node, st, mid);
    build(arr, tree, 2 * node + 1, mid + 1, en);

    if (tree[2 * node].first < tree[2 * node + 1].first)
    {
        tree[node].first = tree[2 * node].first;
        tree[node].second = tree[2 * node].second;
    }
    else if (tree[2 * node + 1].first < tree[2 * node].first)
    {
        tree[node].first = tree[2 * node + 1].first;
        tree[node].second = tree[2 * node + 1].second;
    }
    else
    {
        tree[node].first = tree[2 * node].first;
        tree[node].second = tree[2 * node].second + tree[2 * node + 1].second;
    }
}

pair<int, int> query(vector<pair<int, int>> &tree, int node, int st, int en, int l, int r)
{
    if (st > r || en < l)
        return {INT_MAX, 0};
    else if (st >= l && en <= r)
        return tree[node];

    int mid = (st + en) / 2;
    pair<int, int> q1 = query(tree, 2 * node, st, mid, l, r);
    pair<int, int> q2 = query(tree, 2 * node + 1, mid + 1, en, l, r);

    pair<int, int> q;
    if (q1.first < q2.first)
        q = q1;
    if (q1.first > q2.first)
        q = q2;
    else
        q = {q1.first, q1.second + q2.second};

    return q;
}

void update(vector<int> &arr, vector<pair<int, int>> &tree, int node, int st, int en, int index, int val)
{
    if (st == en)
    {
        arr[st] = val;
        tree[node].first = val;
        tree[node].second = 1;
        return;
    }

    int mid = (st + en) / 2;
    if (index <= mid)
        update(arr, tree, 2 * node, st, mid, index, val);
    else
        update(arr, tree, 2 * node + 1, mid + 1, en, index, val);

    if (tree[2 * node].first < tree[2 * node + 1].first)
    {
        tree[node].first = tree[2 * node].first;
        tree[node].second = tree[2 * node].second;
    }
    else if (tree[2 * node + 1].first < tree[2 * node].first)
    {
        tree[node].first = tree[2 * node + 1].first;
        tree[node].second = tree[2 * node + 1].second;
    }
    else
    {
        tree[node].first = tree[2 * node].first;
        tree[node].second = tree[2 * node].second + tree[2 * node + 1].second;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> arr(n, 0);
    vector<pair<int, int>> tree(2 * n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    build(arr, tree, 1, 0, n - 1);

    while (m--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int index, val;
            cin >> index >> val;
            update(arr, tree, 1, 0, n - 1, index, val);
        }
        else if (type == 2)
        {
            int l, r;
            cin >> l >> r;
            pair<int, int> ans = query(tree, 1, 0, n - 1, l, r - 1);
            cout << ans.first << " " << ans.second << endl;
        }
        else
            break;
    }
}
