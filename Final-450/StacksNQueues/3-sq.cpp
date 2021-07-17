#include <bits/stdc++.h>
using namespace std;
#define ll long long

void push1(int *arr, int x, int &top1, int &top2)
{
    if (top1 + 1 == top2)
    {
        cout << "Stack 1 Full" << endl;
        return;
    }
    top1++;
    arr[top1] = x;
}

void push2(int *arr, int x, int &top1, int &top2)
{
    if (top2 - 1 == top1)
    {
        cout << "Stack 2 Full" << endl;
        return;
    }
    top2--;
    arr[top2] = x;
}

void pop1(int *arr, int &top1)
{
    if (top1 == -1)
    {
        cout << "Stack 1 Empty" << endl;
        return;
    }
    arr[top1] = -1;
    top1--;
}

void pop2(int *arr, int &top2)
{
    if (top2 == (sizeof(arr) / sizeof(arr[0])))
    {
        cout << "Stack 2 Empty" << endl;
        return;
    }
    arr[top2] = -1;
    top2++;
}

void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = -1;
    }

    int top1 = -1, top2 = n;
    push1(arr, 2, top1, top2);
    push2(arr, 5, top1, top2);
    push1(arr, 7, top1, top2);

    print(arr, n);

    push1(arr, 21, top1, top2);
    push1(arr, 8, top1, top2);
    push2(arr, 12, top1, top2);

    print(arr, n);

    pop1(arr, top1);

    print(arr, n);

    pop1(arr, top1);
    pop2(arr, top2);

    print(arr, n);
}