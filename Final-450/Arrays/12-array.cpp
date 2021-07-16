#include <bits/stdc++.h>
using namespace std;
#define ll long long

/* Complexity = O(n) */

void merge(int *arr1, int *arr2, int n1, int n2)
{
    int i = 0, j = 0;
    while (i < n1)
    {
        if (arr1[i] > arr2[j])
        {
            swap(arr1[i], arr2[j]);
        }
        while (arr1[i] > arr2[j + 1])
        {
                }
        i++;
    }

    int prev = 0;
    for (int i = 1; i < n2; i++)
    {
        if (arr2[i] < arr2[0])
            swap(arr2[0], arr2[prev]);
        prev = i;
    }
}

int main()
{
    int n1, n2;
    cin >> n1 >> n2;

    int *arr1 = new int[n1];
    int *arr2 = new int[n2];

    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }

    merge(arr1, arr2, n1, n2);

    for (int i = 0; i < n1; i++)
    {
        cout << arr1[i] << " ";
    }
    for (int i = 0; i < n2; i++)
    {
        cout << arr2[i] << " ";
    }
}