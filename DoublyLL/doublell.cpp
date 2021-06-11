#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

Node *head = NULL;

void getNewNode(int x)
{
    Node *temp = new Node();
    temp->data = x;
    temp->next = NULL;
    temp->prev = NULL;
}

void insertAtBeginning(int x)
{
    Node *temp = new Node();
    temp->data = x;
    if (head == NULL)
    {
        head = temp;
        return;
    }
    head->prev = temp;
    temp->next = head;
    head = temp;
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

void printReverse()
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
}

int main()
{
    insertAtBeginning(2);
    insertAtBeginning(4);
    insertAtBeginning(5);
    insertAtBeginning(6);
    print();
    cout << endl;
    printReverse();
    cout << endl;
}