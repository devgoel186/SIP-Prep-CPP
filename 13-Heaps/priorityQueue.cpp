#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    priority_queue<int, vector<int>> pq;
    pq.push(2);
    pq.push(3);
    pq.push(1);
    cout << pq.top() << endl;

    priority_queue<int, vector<int>, greater<int>> pqMin;
    pqMin.push(1);
    pqMin.push(41);
    pqMin.push(1);
    cout << pqMin.top() << endl;
    cout << pqMin.size() << endl;
}