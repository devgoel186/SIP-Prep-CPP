#include <iostream>
using namespace std;

int n;
int *arr;
int front = -1;
int rear = -1;

bool isEmpty()
{
    if (front == -1 && rear == -1)
        return true;
    return false;
}

void enqueue(int x)
{
    if (front == (rear + 1) % n)
    {
        cout << "Stack Full" << endl;
        return;
    }
    else if (isEmpty())
    {
        front = 0;
        rear = 0;
    }
    else
        rear = (rear + 1) % n;
    arr[rear] = x;
}

void frontElement()
{
    cout << arr[front] << endl;
}

void dequeue()
{
    if (isEmpty())
    {
        cout << "Stack Empty" << endl;
        return;
    }
    else if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % n;
}

void print()
{
    if (isEmpty())
    {
        cout << "Queue is Empty" << endl;
        return;
    }
    int i;
    for (i = front; i % n != rear; i++)
        cout << arr[i] << " ";
    cout << arr[i % n] << endl;
}

int main()
{
    cin >> n;
    arr = new int[n];
    // print();
    enqueue(2);
    print();
    enqueue(12);
    print();
    enqueue(21);
    dequeue();
    print();
    enqueue(9);
    enqueue(112);
    print();
    dequeue();

    // 12 21 9 112
}