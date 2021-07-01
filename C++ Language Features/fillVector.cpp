#include <vector>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> *v = new vector<int>(n);
    for (auto &i : *v)
    {
        cin >> i;
    }

    for (auto i : *v)
    {
        cout << i << " ";
    }
}