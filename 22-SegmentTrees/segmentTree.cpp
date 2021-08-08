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
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(vector<int> &tree, int node, int st, int en, int l, int r)
{
    if (st > r || en < l)
        return 0;
    else if (st >= l && en <= r)
        return tree[node];

    int mid = (st + en) / 2;
    int q1 = query(tree, 2 * node, st, mid, l, r);
    int q2 = query(tree, 2 * node + 1, mid + 1, en, l, r);

    return q1 + q2;
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
            int ans = query(tree, 1, 0, n - 1, l, r);
            cout << ans << endl;
        }
        else
            break;
    }

    cout << "Tree = ";
    for (int i = 1; i <= 15; i++)
        cout << tree[i] << " ";

    /* Sample Tree */
    /* 
    8
    5 3 2 4 1 8 6 10
    */
}