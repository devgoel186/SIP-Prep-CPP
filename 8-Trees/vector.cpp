#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);

    v[1] = 100;
    v[2] = 1004;
    v[4] = 2134;

    v.push_back(41);
    v.push_back(42);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}