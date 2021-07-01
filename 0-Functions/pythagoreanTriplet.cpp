#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

bool checkTriplet(vector<int> *v)
{
    for (auto &i : *v)
    {
        i *= i;
    }

    int n = v->size();
    sort(v->begin(), v->end());

    for (int i = n - 1; i >= 2; i--)
    {
        int l = 0;
        int r = i - 1;
        while (l < r)
        {
            if (v->at(l) + v->at(r) == v->at(i))
                return true;
            v->at(l) + v->at(r) < v->at(i) ? l++ : r--;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    if (n < 3)
    {
        cout << "Invalid Input. Less Than 3 Elements!" << endl;
        exit(0);
    }

    vector<int> *v = new vector<int>(n);

    for (auto &i : *v)
    {
        cin >> i;
    }

    cout << checkTriplet(v) << endl;
}