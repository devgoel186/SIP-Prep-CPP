#include <bits/stdc++.h>
using namespace std;
#define long long ll;

int solveKnapsack(int *values, int *weights, int n, int W)
{
    if (n == 0 | W == 0)
        return 0;
    if (weights[n - 1] > W)
        return solveKnapsack(values, weights, n - 1, W);
    return max(solveKnapsack(values, weights, n - 1, W - weights[n - 1]) + values[n - 1], solveKnapsack(values, weights, n - 1, W));
}

int main()
{
    int W = 50;
    int wt[] = {10, 20, 30};
    int value[] = {100, 50, 150};
    cout << solveKnapsack(value, wt, 3, W) << endl;
}