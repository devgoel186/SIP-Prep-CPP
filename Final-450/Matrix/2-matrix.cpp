#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int m, n;
    cin >> m >> n;
    int **arr = new int *[n];
    for (int i = 0; i < m; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int x;
    cin >> x;
    int i = 0, j = n - 1;
    int flag = 0;
    while (i < n && j >= 0)
    {
        if (arr[i][j] == x)
        {
            cout << i << " " << j << endl;
            break;
        }
        else if (arr[i][j] > x)
            j--;
        else if (arr[i][j] < x)
            i++;
        else
        {
            break;
        }
    }
}