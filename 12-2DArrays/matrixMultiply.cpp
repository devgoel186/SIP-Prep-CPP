#include <iostream>
using namespace std;

int **multiply(int **arr1, int **arr2, int n1, int n2, int n3)
{
    int **arr3 = new int *[n1];
    for (int i = 0; i < n1; i++)
    {
        arr3[i] = new int[n3];
        for (int j = 0; j < n3; j++)
        {
            arr3[i][j] = 0;
        }
    }

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n3; j++)
        {
            for (int k = 0; k < n2; k++)
            {
                arr3[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    return arr3;
}

void print(int **arr, int n1, int n2)
{
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int **arr = new int *[n1];
    int **arr2 = new int *[n2];

    for (int i = 0; i < n1; i++)
    {
        arr[i] = new int[n2];
        for (int j = 0; j < n2; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n2; i++)
    {
        arr2[i] = new int[n3];
        for (int j = 0; j < n3; j++)
        {
            cin >> arr2[i][j];
        }
    }

    int **arr3 = multiply(arr, arr2, n1, n2, n3);
    print(arr, n1, n2);
    cout << endl;
    print(arr2, n2, n3);
    cout << endl;
    print(arr3, n1, n3);
    cout << endl;
}