#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node
{
    int data;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        prev = NULL;
    }
};

Node *tail = NULL;

void printLL(Node *node)
{
    if (node == NULL)
        return;
    printLL(node->prev);
    cout << node->data;
}

void multiply(int n, int i)
{
    if (tail == NULL)
    {
        tail = new Node(i);
        return;
    }

    Node *temp = tail;
    int carry = 0;

    while (temp != NULL)
    {
        temp->data = temp->data * i + carry;
        carry = temp->data / 10;
        temp->data = temp->data % 10;
        if (temp->prev == NULL)
            break;
        temp = temp->prev;
    }

    while (carry != 0)
    {
        temp->prev = new Node(carry % 10);
        carry /= 10;
        temp = temp->prev;
    }
}

int main()
{
    int n;
    cin >> n;
    if (n <= 1)
    {
        cout << 1 << endl;
        exit(0);
    }

    for (int i = 2; i <= n; i++)
    {
        multiply(n, i);
    }

    printLL(tail);
}