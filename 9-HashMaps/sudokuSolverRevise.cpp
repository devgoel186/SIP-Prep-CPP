#include <bits/stdc++.h>
using namespace std;

bool isSafe(const vector<vector<int>> &grid, int row, int col, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (grid[row][i] == num)
            return false;
    }

    for (int j = 0; j < 9; j++)
    {
        if (grid[j][col] == num)
            return false;
    }

    int rowStart = row - row % 3;
    int colStart = col - col % 3;
    for (int i = rowStart; i < rowStart + 3; i++)
    {
        for (int j = colStart; j < colStart + 3; j++)
        {
            if (grid[i][j] == num)
                return false;
        }
    }

    return true;
}

bool solveSudoku(vector<vector<int>> &grid, int row, int col)
{
    if (row == 8 && col == 9)
    {
        return true;
    }

    if (col == 9)
    {
        row++;
        col = 0;
    }

    for (int i = 1; i <= 9; i++)
    {
        if (isSafe(grid, row, col, i))
        {
            grid[row][col] = i;
            if (solveSudoku(grid, row, col + 1))
                return true;
        }
        grid[row][col] = 0;
    }

    return false;
}

void print(const vector<vector<int>> &grid)
{
    for (auto i : grid)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> grid{{3, 0, 6, 5, 0, 8, 4, 0, 0},
                             {5, 2, 0, 0, 0, 0, 0, 0, 0},
                             {0, 8, 7, 0, 0, 0, 0, 3, 1},
                             {0, 0, 3, 0, 1, 0, 0, 8, 0},
                             {9, 0, 0, 8, 6, 3, 0, 0, 5},
                             {0, 5, 0, 0, 9, 0, 6, 0, 0},
                             {1, 3, 0, 0, 0, 0, 2, 5, 0},
                             {0, 0, 0, 0, 0, 0, 0, 7, 4},
                             {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    if (solveSudoku(grid, 0, 0))
        print(grid);
}