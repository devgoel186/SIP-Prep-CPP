#include <iostream>
#include <vector>
using namespace std;

void sieveLogic(int n)
{
    vector<int> arr(n, 0);

    for (int i = 2; i <= n; i++)
    {
        if (arr[i] == 0)
        {
            for (int j = i * i; j <= n; j += i)
            {
                arr[j] = 1;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (arr[i] == 0)
            cout << i << " ";
    }
    cout << endl;
}

/* Complexity = O(n log(log n))) */

int main()
{
    int n;
    cin >> n;
    sieveLogic(n);
}