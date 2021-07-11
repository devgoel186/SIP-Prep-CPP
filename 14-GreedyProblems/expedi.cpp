#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> stops(n);
    for (int i = 0; i < n; i++)
    {
        cin >> stops[i].first >> stops[i].second;
    }
    int l, p;
    cin >> l >> p;

    for (int i = 0; i < n; i++)
    {
        stops[i].first = l - stops[i].first;
    }

    sort(stops.begin(), stops.end(), [&](pair<int, int> p1, pair<int, int> p2)
         { return p1.first < p2.first; });

    int ans = 0;
    int curr = p;
    bool flag = false;

    priority_queue<int, vector<int>> pq;

    for (int i = 0; i < n; i++)
    {
        if (curr >= l)
        {
            break;
        }

        while (curr < stops[i].first)
        {
            if (pq.empty())
            {
                flag = true;
                break;
            }
            ans++;
            curr += pq.top();
            pq.pop();
        }

        if (flag)
            break;
        pq.push(stops[i].second);
    }
    while (!pq.empty() && curr < l)
    {
        curr += pq.top();
        pq.pop();
        ans++;
    }
    if (curr < l)
        flag = true;
    if (flag)
    {
        cout << "Reaching destination is not possible!" << endl;
        exit(0);
    }
    cout << ans << endl;
}