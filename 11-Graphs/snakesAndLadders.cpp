#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int ladders, snakes;
    map<int, int> lad, snak;
    cin >> ladders;
    for (int i = 0; i < ladders; i++)
    {
        int u, v;
        cin >> u >> v;
        lad[u] = v;
    }
    cin >> snakes;
    for (int i = 0; i < snakes; i++)
    {
        int u, v;
        cin >> u >> v;
        snak[u] = v;
    }

    int moves = 0;
    queue<int> q;
    q.push(1);
    bool found = false;
    vector<bool> visited(101, false);
    visited[1] = true;

    while (!q.empty() && !found)
    {
        int size = q.size();
        while (size--)
        {
            int t = q.front();
            q.pop();
            for (int die = 1; die <= 6 && !found; die++)
            {
                if (t + die == 100)
                    found = true;
                if (t + die <= 100 && lad[t + die] && !visited[lad[t + die]])
                {
                    visited[lad[t + die]] = true;
                    if (lad[t + die] == 100)
                        found = true;
                    q.push(lad[t + die]);
                }
                else if (t + die <= 100 && snak[t + die] && !visited[snak[t + die]])
                {
                    visited[snak[t + die]] = true;
                    if (snak[t + die] == 100)
                        found = true;
                    q.push(snak[t + die]);
                }
                else if (t + die <= 100 && !snak[t + die] && !snak[t + die] && !visited[t + die])
                {
                    visited[t + die] = true;
                    q.push(t + die);
                }
            }
            if (found)
                break;
        }
        moves++;
    }

    if (found)
        cout << "Reached 100 in " << moves << " moves!" << endl;
    else
        cout << "Couldn't reach 100" << endl;
}