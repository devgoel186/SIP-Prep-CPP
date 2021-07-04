#include <iostream>
using namespace std;

int pathsPossibleInMazeGame(int n, int i, int j)
{
    if (i == n - 1 || j == n - 1)
        return 1;
    if (i >= n || j >= n)
        return 0;
    return pathsPossibleInMazeGame(n, i + 1, j) + pathsPossibleInMazeGame(n, i, j + 1);
}

int pathsPossibleInBoardGame(int s, int e)
{
    if (s == e)
        return 1;

    if (s > e)
        return 0;

    int count = 0;
    for (int i = 1; i <= 6; i++)
    {
        count += pathsPossibleInBoardGame(s + i, e);
    }
    return count;
}

int main()
{
    int start, end;
    cin >> start >> end;
    cout << "Board Game : " << pathsPossibleInBoardGame(start, end) << endl;
    int n;
    cin >> n;
    cout << "Maze Game : " << pathsPossibleInMazeGame(n, 0, 0) << endl;
}