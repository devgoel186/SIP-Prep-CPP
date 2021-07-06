#include <iostream>
#include <deque>
using namespace std;
#define long long ll;

int main()
{
    deque<int> dq;
    dq.push_back(1);
    dq.push_front(3);
    dq.push_back(4);
    dq.push_back(12);
    dq.push_front(7);
    for (auto i : dq)
    {
        cout << i << " ";
    }
    cout << "\nSize = " << dq.size() << endl;
}