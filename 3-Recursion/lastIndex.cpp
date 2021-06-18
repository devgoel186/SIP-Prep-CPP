#include <iostream>
using namespace std;

int calculate(int *arr, int size, int x)
{
    if (size == 0)
        return -1;
    if (arr[0] == x)
        return 0;
    return calculate(arr + 1, size - 1, x) + 1;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int result = calculate(arr, n, 4);
    cout << result << endl;
}