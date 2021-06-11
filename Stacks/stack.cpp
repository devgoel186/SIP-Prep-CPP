#include <iostream>
using namespace std;

int n;
int *arr;
int top = -1;

void push(int x)
{
    if (top == n - 1)
    {
        cout << "Stack Full" << endl;
        return;
    }
    arr[++top] = x;
}

void pop()
{
    if (top == -1)
    {
        cout << "Stack Empty" << endl;
        return;
    }
    top--;
}

void topElement()
{
    if (top == -1)
    {
        cout << "Stack Empty" << endl;
        return;
    }
    cout << arr[top];
}

void print()
{
    for (int i = 0; i <= top; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    cin >> n;
    arr = new int[n];
    push(2);
    push(24);
    push(11);
    print();
    push(312);
    pop();
    pop();
    print();
    push(21);
    push(90);
    print();
    pop();
    print();
}