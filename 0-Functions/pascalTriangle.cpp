#include <iostream>
using namespace std;

int main()
{
    cout << "PASCAL'S TRIANGLE" << endl;
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int temp = 1;
        for (int j = 1; j <= i; j++)
        {
            cout << temp << " ";
            temp *= (i - j) / j;
        }
        cout << endl;
    }
}