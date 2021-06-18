#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head;

void insertAtBeginning(int x)
{
    Node *temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
}

void insertAtN(int i, int x)
{
    Node *temp = head;
    Node *temp2 = new Node();
    temp2->data = x;
    if (i == 1)
    {
        temp2->next = head;
        head = temp2;
        return;
    }
    i -= 2;
    while (i--)
    {
        temp = temp->next;
    }
    temp2->next = temp->next;
    temp->next = temp2;
}

void deleteAtN(int i)
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "List empty!" << endl;
    }
    if (i == 1)
    {
        head = temp->next;
        delete temp;
        return;
    }
    i -= 2;
    while (i--)
    {
        temp = temp->next;
    }
    Node *del = temp->next;
    temp->next = del->next;
    delete del;
}

void reverse()
{
    Node *temp = head;
    Node *prev = NULL;
    Node *next = new Node();
    while (temp != NULL)
    {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    head = prev;
}

void reverseRecursive(Node *temp)
{
    if (temp->next == NULL)
    {
        head = temp;
        return;
    }
    reverseRecursive(temp->next);
    Node *q = temp->next;
    q->next = temp;
    temp->next = NULL;
}

void print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void printRecursive(Node *temp)
{
    if (temp == NULL)
        return;
    cout << temp->data << " ";
    printRecursive(temp->next);
}

void printReverseRecursive(Node *temp)
{
    if (temp == NULL)
        return;
    printReverseRecursive(temp->next);
    cout << temp->data << " ";
}

int main()
{
    head = NULL;
    // int n, x;
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> x;
    //     insertAtBeginning(x);
    // }
    insertAtBeginning(4);
    insertAtBeginning(2);
    insertAtBeginning(8);
    insertAtBeginning(1);
    insertAtN(2, 5);
    insertAtN(4, 12);
    insertAtN(6, 329);
    deleteAtN(2);
    deleteAtN(6);
    deleteAtN(2);
    // deleteAtN(1);
    // insertAtN(1, 1);
    // insertAtN(2, 8);
    // insertAtN(1, 3);
    // reverse();
    print();
    cout << endl;
    reverseRecursive(head);
    print();
    cout << endl;
    printReverseRecursive(head);
    cout << endl;
}

// 1 12 2 329