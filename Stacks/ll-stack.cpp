#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head;

void push(int x)
{
    Node *temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
}

void pop()
{
    Node *temp = new Node();
    if (head == NULL)
    {
        cout << "Stack empty" << endl;
        return;
    }
    temp = head;
    head = head->next;
    delete temp;
}

void top()
{
    if (head == NULL)
    {
        cout << "Stack empty" << endl;
        return;
    }
    cout << head->data;
}

void print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    head = NULL;
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