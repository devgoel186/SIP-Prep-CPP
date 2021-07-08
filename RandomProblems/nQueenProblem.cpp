#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isSafe(int **arr, int row, int col, int n)
{
    /* Check all rows in the given column above the index */
    for (int i = 0; i < row; i++)
    {
        if (arr[i][col] == 1)
            return false;
    }

    /* Checking left diagonal above */
    int i = row;
    int j = col;
    while (i >= 0 && j >= 0)
    {
        if (arr[i][j] == 1)
            return false;
        i--;
        j--;
    }

    /* Checking right diagonal above */
    i = row;
    j = col;
    while (i >= 0 && j < n)
    {
        if (arr[i][j] == 1)
            return false;
        i--;
        j++;
    }

    /* If no issues found return true */
    return true;
}

bool nQueen(int **arr, int row, int n)
{
    /* If already n queens are put, return true */
    if (row >= n)
        return true;

    /* Loop for each column in a row, and call recursion for next row */
    for (int i = 0; i < n; i++)
    {
        if (isSafe(arr, row, i, n))
        {
            arr[row][i] = 1;
            if (nQueen(arr, row + 1, n))
                return true;
            arr[row][i] = 0; /* Backtrack */
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 0;
        }
    }

    if (nQueen(arr, 0, n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
}