#include <bits/stdc++.h>
using namespace std;
#define ll long long

priority_queue<int, vector<int>> pqmax;
priority_queue<int, vector<int>, greater<int>> pqmin;

double findMedian()
{
    if (pqmax.size() == pqmin.size())
        return (pqmax.top() + pqmin.top()) / 2.0;
    else if (pqmax.size() > pqmin.size())
        return pqmax.top();
    return pqmin.top();
}

void insert(int x)
{
    if (pqmax.size() == pqmin.size())
    {
        if (pqmax.size() == 0)
        {
            pqmax.push(x);
            return;
        }

        if (x < pqmax.top())
            pqmax.push(x);
        else
            pqmin.push(x);
    }
    else
    {
        if (pqmax.size() > pqmin.size())
        {
            if (x >= pqmax.top())
                pqmin.push(x);
            else
            {
                int temp = pqmax.top();
                pqmax.pop();
                pqmin.push(temp);
                pqmax.push(x);
            }
        }
        else
        {
            if (x <= pqmax.top())
                pqmax.push(x);
            else
            {
                int temp = pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                pqmin.push(x);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    do
    {
        insert(n);
        cout << findMedian() << endl;
        cin >> n;
    } while (n != -1);
}
