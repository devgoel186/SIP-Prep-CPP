#include <bits/stdc++.h>
using namespace std;
#define ll long long

void change(vector<vector<char>> &grid, int i, int j)
{
    grid[i][j] = '*';
    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};
    for (int k = 0; k < 4; k++)
    {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx < grid.size() && nx >= 0 && ny < grid.size() && ny >= 0 && grid[nx][ny] == 'O')
            change(grid, nx, ny);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n, '*'));

    for (auto &i : grid)
    {
        for (auto &j : i)
        {
            cin >> j;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
            {
                if (grid[i][j] == 'O')
                {
                    change(grid, i, j);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 'O')
            {
                grid[i][j] = 'X';
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '*')
            {
                grid[i][j] = 'O';
            }
        }
    }

    cout << endl;
    for (auto i : grid)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}